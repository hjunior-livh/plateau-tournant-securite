import { Chart, ChartDataset } from "chart.js/auto"
import { EngineCurrentEntry } from "./DataSchematics";


function engineCurrentRender(): void {
    if (this.chart === undefined) {
        this.chart = new Chart(
            this.ctx,
            {
                type: "line",
                data: {
                    labels: this.data.map((row: EngineCurrentEntry) =>
                        `${row.horodatage.split(' ')[1]} (${row.id})`),
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
        this.chart.data.labels = this.data.map((row: EngineCurrentEntry) => `${row.horodatage.split(' ')[1]} (${row.id})`);
        this.chart.data.datasets.forEach((dataset: ChartDataset) =>
            dataset.data = this.data.map((row: EngineCurrentEntry) =>
                row.valeur
            )
        );
        this.chart.update();
    }
}


// function ...Render() : void {
// ..

export function getRenderMethod(chartId: string): Function {
    switch (chartId) {
        case "engine-current":
            return engineCurrentRender;
        // case "...":
        // return ...
        default:
            throw new Error(`Invalid chartId "${chartId}": render not found`);
    }
}