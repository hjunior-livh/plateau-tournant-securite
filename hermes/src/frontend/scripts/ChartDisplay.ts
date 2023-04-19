import Chart, { ChartItem } from "chart.js/auto"


interface DataRow {
    id?: number,
    horodata?: string,
    valeur?: number,
    horodatage?: string
}


export class ChartDisplay {

    private canvasId: string;
    private dataTable: string;
    private dataEntryNumber: number;
    private canvas: HTMLElement | null;
    private ctx: CanvasRenderingContext2D | null;
    private data: DataRow[];
    private chart: Chart;
    private xhr: XMLHttpRequest;

    constructor(canvasId: string, dataTable: string, dataEntryNumber: number) {
        this.canvasId = canvasId;
        this.dataTable = dataTable;
        this.dataEntryNumber = dataEntryNumber;
        this.canvas = document.getElementById(this.canvasId);
        if (this.canvas === null) {
            throw new Error("Invalid canvasID");
        }
        this.ctx = (this.canvas as HTMLCanvasElement).getContext("2d");
        if (this.ctx === null) {
            throw new Error("Unable to get 2D context");
        }
        this.data = [];
        this.chart;
        this.xhr = new XMLHttpRequest();
    }

    public updateData() : void {
        this.xhr.open("GET", `/api/${this.dataTable}/${this.dataEntryNumber}/`);
        this.xhr.send();
        this.xhr.onload = () => {
            if (this.xhr.readyState === this.xhr.DONE) {
                if (this.xhr.status === 200) {
                    this.data = JSON.parse(this.xhr.responseText);
                    this.data.sort((a:any, b:any) => (a.id - b.id));
                    console.log(this.data);
                    this.render();
                } else {
                    //TODO
                }
            } else {
                // Peut-être TODO
            }
        };
    }

    private render() : void {
        console.log("render called!")
        if (this.chart === undefined) {
            this.chart = new Chart(
                this.ctx as CanvasRenderingContext2D,
                {
                    type: "line",
                    data: {
                        labels: this.data.map((row: any) => `${row.horodatage.split(' ')[1]} (${row.id})`),
                        datasets: [
                            {
                                data: this.data.map((row: any) => row.valeur),
                                label: "Courant du moteur relevé par le capteur",
                                fill: true
                            }
                        ]
                    }
                }
            );
        } else {
            this.chart.data.labels = this.data.map((row: any) => `${row.horodatage.split(' ')[1]} (${row.id})`);
            this.chart.data.datasets.forEach((dataset: any) => dataset.data = this.data.map(row => row.valeur));
            this.chart.update();
        }
    }
}