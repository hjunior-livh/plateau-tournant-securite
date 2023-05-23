import { Chart, ChartDataset } from "chart.js/auto"
import { EngineCurrentEntry } from "../../types/ChartDataTypes";


export function engineCurrentRender(): void {
    if (this.chart === undefined) {
        this.chart = new Chart(
            this.ctx,
            {
                type: "line",
                data: {
                    labels: this.data.map((row: EngineCurrentEntry) => new Date(row.epoch).toLocaleString('fr-FR')),
                    datasets: [
                        {
                            data: this.data.map((row: EngineCurrentEntry) => row.valeur),
                            label: "Courant du moteur relevé par le capteur",
                            fill: true
                        }
                    ]
                }
            }
        );
    } else {
        this.chart.data.labels = this.data.map((row: EngineCurrentEntry) => new Date(row.epoch).toLocaleString('fr-FR'));
        this.chart.data.datasets.forEach((dataset: ChartDataset) =>
            dataset.data = this.data.map((row: EngineCurrentEntry) =>
                row.valeur
            )
        );
        this.chart.update();
    }
}