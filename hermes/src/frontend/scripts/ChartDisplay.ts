import { Chart, ChartItem } from "chart.js/auto"
import { Dataset } from "./DataSchematics";




export class ChartDisplay {

    private HTMLElementId: string;
    private dataTable: string;
    private defaultDataQuantity: number;
    private canvas: HTMLElement | null;
    private ctx: CanvasRenderingContext2D | null;
    private data: Dataset[];
    private chart: Chart;
    private xhr: XMLHttpRequest;
    private render: Function;


    constructor(HTMLElementId: string, dataTable: string, defaultDataQuantity: number) {
        this.HTMLElementId = HTMLElementId;
        this.dataTable = dataTable;
        this.defaultDataQuantity = defaultDataQuantity;
        this.canvas = document.getElementById(this.HTMLElementId);
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

    public updateData(): void {
        this.xhr.open("GET", `/api/${this.dataTable}/${this.defaultDataQuantity}/`);
        this.xhr.send();
        this.xhr.onload = () => {
            if (this.xhr.readyState === this.xhr.DONE) {
                if (this.xhr.status === 200) {
                    this.data = JSON.parse(this.xhr.responseText);
                    this.data.sort((a: any, b: any) => (a.id - b.id));
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

    public setRenderMethod(renderMethod: Function): void {
        this.render = renderMethod;
    }

    // private render() : void {
    //     if (this.chart === undefined) {
    //         this.chart = new Chart(
    //             this.ctx as CanvasRenderingContext2D,
    //             {
    //                 type: "line",
    //                 data: {
    //                     labels: this.data.map((row: any) => `${row.horodatage.split(' ')[1]} (${row.id})`),
    //                     datasets: [
    //                         {
    //                             data: this.data.map((row: any) => row.valeur),
    //                             label: "Courant du moteur relevé par le capteur",
    //                             fill: true
    //                         }
    //                     ]
    //                 }
    //             }
    //         );
    //     } else {
    //         this.chart.data.labels = this.data.map((row: any) => `${row.horodatage.split(' ')[1]} (${row.id})`);
    //         this.chart.data.datasets.forEach((dataset: any) => dataset.data = this.data.map((row: any) => row.valeur));
    //         this.chart.update();
    //     }
    // }
}