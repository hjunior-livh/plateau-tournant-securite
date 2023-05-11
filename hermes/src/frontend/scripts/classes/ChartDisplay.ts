import { Chart } from "chart.js/auto"
import { DataEntry, Dataset } from "../types/ChartDataTypes";
import { ChartDescriptor } from "./ChartDescriptors";


export class ChartDisplay {

    public readonly id: string;
    private HTMLElementId: string;
    public readonly dataTable: string;
    private defaultDataQuantity: number;
    private canvas: HTMLCanvasElement | null;
    private ctx: CanvasRenderingContext2D | null;
    private data: Dataset[];
    private chart: Chart;
    private xhr: XMLHttpRequest;
    private updateDataStream: EventSource;
    public render: Function;


    constructor(chartDescriptor: ChartDescriptor, renderFunction: Function) {
        const { chartId, HTMLElementId, dataTable, defaultDataQuantity } = chartDescriptor;
        this.id = chartId;
        this.HTMLElementId = HTMLElementId;
        this.dataTable = dataTable;
        this.defaultDataQuantity = defaultDataQuantity;
        this.canvas = document.getElementById(this.HTMLElementId) as HTMLCanvasElement;
        if (this.canvas === null) {
            throw new Error("Invalid canvasID");
        }
        this.ctx = this.canvas.getContext("2d");
        if (this.ctx === null) {
            throw new Error("Unable to get 2D context");
        }
        this.data = [];
        this.chart;
        this.xhr = new XMLHttpRequest();
        this.render = renderFunction;
        this.updateDataStream = new EventSource(`api/stream/${dataTable}`);
        this.updateDataStream.addEventListener("new_data", (event) => {
            console.log(event);
            console.log(event.data);
        });
    }


    fetchData(): void {
        this.xhr.open("GET", `/api/get/${this.dataTable}/${this.defaultDataQuantity}/`);
        this.xhr.send();
        this.xhr.addEventListener("load", () => {
            if (this.xhr.readyState === this.xhr.DONE) {
                if (this.xhr.status === 200) {
                    this.data = JSON.parse(this.xhr.responseText);
                    this.data.sort((a: any, b: any) => (a.id - b.id));
                    this.render();
                } else {
                    //TODO: message, erreur, 2n essai ?
                }
            }
        });
    }

    updateData(newData: any[]): void {
        this.data.push(JSON.parse(newData) as DataEntry);
    }
}