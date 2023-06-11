import { BaseChart } from "./BaseChart.js";
import { Chart as ChartJs } from "../lib/chart.js/dist/types/index.js"
import type { SQLChartDescriptor } from "../types/ChartDescriptors.js";
import type { ChartDataset } from "../lib/chart.js/dist/types/index.js"
import type { EngineCurrentEntry, SQLEventDataEntry } from "../types/SQLDatabaseTypes.js";
import type { SQLEventDataset } from "../types/SQLDatabaseTypes.js";

export class SQLChart extends BaseChart {

    override data?: SQLEventDataset
    public readonly dataTable: string;
    private defaultDataQuantity: number;

    constructor(descriptor: SQLChartDescriptor) {
        super(descriptor);
        this.dataTable = descriptor.dataTable;
        this.defaultDataQuantity = descriptor.defaultDataQuantity;
    }

    render(): void {
        if (this.data !== undefined) {
            if (this.chart === undefined) {
                this.chart = new ChartJs(
                    this.ctx,
                    {
                        type: "line",
                        options: {
                            scales: {
                                x: {
                                    ticks: {
                                        autoSkip: false,
                                        maxRotation: 90,
                                        minRotation: 90,
                                        callback: function (value: string | number, index: number): string {
                                            return index % 100 === 0 ? this.getLabelForValue(value as number) : "";
                                        }
                                    }
                                }
                            },
                            plugins: {
                                title: {
                                    display: true,
                                    text: this.chartTitle
                                }
                            },
                            elements: {
                                point: {
                                    radius: 1
                                }
                            }
                        },
                        data: {
                            labels: this.data.map((row: SQLEventDataEntry) =>
                                new Date(Math.floor(row.epoch)).toLocaleString('fr-FR')
                            ),
                            datasets: [
                                {
                                    data: this.data.map((row: SQLEventDataEntry) => (row as EngineCurrentEntry).valeur),
                                    label: this.dataLegend,
                                    borderWidth: 1
                                }
                            ]
                        }
                    }
                );
            } else {
                this.chart.data.labels = this.data.map((row: SQLEventDataEntry) => new Date(Math.floor(row.epoch)).toLocaleString('fr-FR'));
                this.chart.data.datasets[0].data = this.data.map((row: SQLEventDataEntry) => (row as EngineCurrentEntry).valeur);
                this.chart.update();
            }
        }
    }



    fetchData(tryNum: number = 1): void {
        if (tryNum < 5) {
            this.xhr.open("GET", `/api/table/${this.dataTable}/${this.defaultDataQuantity}/`);
            this.xhr.addEventListener("load", () => {
                if (this.xhr.readyState === this.xhr.DONE) {
                    if (this.xhr.status === 200) {
                        let res = JSON.parse(this.xhr.responseText) as SQLEventDataset;
                        this.data = res.sort((a: SQLEventDataEntry, b: SQLEventDataEntry) => (a.epoch - b.epoch));
                        this.render();
                    } else {
                        this.fetchData(tryNum++);
                    }
                }
            });
            this.xhr.send();
        } else {
            throw new Error("Maximum retries limit reached, check your connection");
        }
    }

    updateData(newData: SQLEventDataEntry): void {
        if (this.data !== undefined) {
            this.data.push(newData);
        } else {
            this.data = [newData];
        }
        this.render();
    }
}