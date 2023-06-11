import { BaseChart } from "./BaseChart.js";
import { Chart as ChartJs } from "../lib/chart.js/dist/types/index.js"
import type { CSVChartDiscriptor } from "../types/ChartDescriptors.js";
import type { CSVData } from "../types/CSVDataType.js";


export class CSVChart extends BaseChart {

    override data?: CSVData
    private filename: string;

    constructor(descriptor: CSVChartDiscriptor) {
        super(descriptor);
        this.filename = descriptor.filename;
    }

    fetchData(tryNum: number = 1): void {
        if (tryNum < 5) {
            this.xhr.open("GET", `/api/csv/engine-current/${this.filename}/`);
            this.xhr.addEventListener("load", () => {
                if (this.xhr.readyState === this.xhr.DONE) {
                    if (this.xhr.status === 200) {
                        const res = JSON.parse(this.xhr.responseText);
                        this.data = res.map((value: string) => parseInt(value)) as CSVData;
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
                                            return index % 100 === 0 ? `${index} ms` : "";
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
                            labels: this.data,
                            datasets: [
                                {
                                    data: this.data,
                                    label: this.dataLegend,
                                    borderWidth: 1
                                }
                            ]
                        }
                    }
                );
            } else {
                this.chart.data.labels = this.data;
                this.chart.data.datasets[0].data = this.data;
                this.chart.update();
            }
        }
    }

    updateData(newFilename: string): void {
        this.filename = newFilename;
        this.fetchData();
        this.render();
    }
}