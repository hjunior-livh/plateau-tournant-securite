import { Chart } from "chart.js/auto"
import { Dataset } from "../types/ChartDataTypes";
import { ChartDescriptor } from "./ChartDescriptors";


export class ChartDisplay {

    private HTMLElementId: string;
    private dataTable: string;
    private defaultDataQuantity: number;
    private canvas: HTMLCanvasElement | null;
    private ctx: CanvasRenderingContext2D | null;
    private data: Dataset[];
    private chart: Chart;
    private xhr: XMLHttpRequest;
    public render: Function;

    /**
     * 
     * @param chartDescriptor 
     */
    constructor(chartDescriptor: ChartDescriptor, renderFunction: Function) {
        const { HTMLElementId, dataTable, defaultDataQuantity } = chartDescriptor;
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
    }

    /**
     * 
     * @returns Promise<void>
     */
    async updateData(): Promise<void> {
        this.xhr.open("GET", `/api/${this.dataTable}/${this.defaultDataQuantity}/`);
        this.xhr.send();

        return new Promise<void>((resolve) => {
            this.xhr.addEventListener("load", () => {
                if (this.xhr.readyState === this.xhr.DONE) {
                    if (this.xhr.status === 200) {
                        this.data = JSON.parse(this.xhr.responseText);
                        this.data.sort((a: any, b: any) => (a.id - b.id));
                        resolve();
                    } else {
                        //TODO: message, erreur, 2n essai ?
                    }
                } 
            });
        });
    }
}