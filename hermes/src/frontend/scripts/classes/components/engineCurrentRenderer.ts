import type { ChartDataset } from "../../lib/chart.js/dist/types/index.d.ts"
import {Chart} from "../../lib/chart.js/dist/types/index.js"
import { EngineCurrentEntry, EventDataEntry } from "../../types/DatabaseTypes.js";
import { ChartDisplay } from "../ChartDisplay.js";
import { ChartRenderer } from "./ChartRenderInterface.js";


let engineCurrentRenderer: ChartRenderer;

engineCurrentRenderer = function(this: ChartDisplay): void {
    if (this.chart === undefined) {
        this.chart = new Chart(
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
                                callback: function (value: string | number, index: number) : string {
                                    // Hide every 100th tick label
                                    return index % 100 === 0 ? this.getLabelForValue(value as number) : "";
                                    // return new Date(this.getLabelForValue(Math.floor((value as number) / 1000))) !== new Date(this.getLabelForValue(Math.floor(((value as number) -1) / 1000))) ? this.get ;
                                }
                            }
                        }
                    },
                    plugins: {
                        title: {
                            display: true,
                            text: "Courant moteur"
                        }
                    },
                    elements: {
                        point: {
                            radius: 1
                        }
                    }
                },
                data: {
                    labels: this.data.map((row: EventDataEntry) =>
                        new Date(Math.floor(row.epoch)).toLocaleString('fr-FR')
                    ),
                    datasets: [
                        {
                            data: this.data.map((row: EventDataEntry) => (row as EngineCurrentEntry).valeur),
                            label: "Courant du moteur relevé par le capteur",
                            borderWidth: 1
                        }
                    ]
                }
            }
        );
    } else {
        this.chart.data.labels = this.data.map((row: EventDataEntry) => new Date(Math.floor(row.epoch)).toLocaleString('fr-FR'));
        this.chart.data.datasets.forEach((dataset: ChartDataset) =>
            dataset.data = this.data.map((row: EventDataEntry) =>
                (row as EngineCurrentEntry).valeur
            )
        );
        this.chart.update();
    }
}

export { engineCurrentRenderer };
