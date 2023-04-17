import Chart, { ChartItem } from "chart.js/auto"


interface DataRowSchematic {
    id?: number,
    horodata?: string,
}



export class ChartDisplay {

    private canvasId: string;
    private canvas: HTMLElement | null;
    private ctx: CanvasRenderingContext2D | null;
    private data: Object[];
    private chart: Chart;


    constructor(canvasId: string) {
        this.canvasId = canvasId;
        this.canvas = document.getElementById(this.canvasId);
        if (this.canvas === null) {
            throw new Error("Invalid canvasID");
        }
        this.ctx = (this.canvas as HTMLCanvasElement).getContext("2d");
        this.data;
        this.chart;
    }

    render() {
        if (this.chart === undefined) {
            this.chart = new Chart(
                <ChartItem>this.canvas,
                {
                    type: "line",
                    data: {
                        labels: this.data.map(row => `${row.horodatage.split(' ')[1]} (${row.id})`),
                        datasets: [
                            {
                                data: this.data.map(row => row.valeur),
                                label: "Courant du moteur relevé par le capteur",
                                fill: true
                            }
                        ]
                    }
                }
            );
        } else {
            this.chart.data.labels = this.data.map(row => `${row.horodatage.split(' ')[1]} (${row.id})`);
            this.chart.data.datasets.forEach((dataset) => dataset.data = this.data.map(row => row.valeur));
            this.chart.update();
        }
    }

    updateData() {

    }
}