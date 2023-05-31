import type { Chart, ChartItem } from "../lib/chart.js/dist/types/index.js"
import { EventDataEntry, EventDataset } from "../types/DatabaseTypes.js";
import { ChartDescriptor } from "./ChartDescriptors.js";
import { engineCurrentRenderer } from "./components/engineCurrentRenderer.js";
import { ChartRenderer } from "./components/ChartRenderInterface.js";


export class ChartDisplay {

    public readonly id: string;
    private HTMLElementId: string;
    public readonly dataTable: string;
    private defaultDataQuantity: number;
    private canvas: HTMLCanvasElement | null;
    private _ctx: ChartItem;
    private _data: EventDataset;
    private _chart?: Chart;
    private xhr: XMLHttpRequest;
    public render: ChartRenderer;

    constructor(chartDescriptor: ChartDescriptor) {
        let renderFunction: ChartRenderer;

        this.id = chartDescriptor.chartId;
        this.HTMLElementId = chartDescriptor.HTMLElementId;
        this.dataTable = chartDescriptor.dataTable;
        this.defaultDataQuantity = chartDescriptor.defaultDataQuantity;
        this.canvas = document.getElementById(this.HTMLElementId) as HTMLCanvasElement | null; // !!!
        if (this.canvas === null) {
            throw new Error("Invalid canvasID");
        }
        this._ctx = this.canvas.getContext("2d") as ChartItem;
        if (this._ctx === null) {
            throw new Error("Unable to get 2D context");
        }
        this._data = [];
        this.xhr = new XMLHttpRequest();
        switch (chartDescriptor.chartId) {
            case "engine-current":
                renderFunction = engineCurrentRenderer;
                break;
            // case "...":
            //     module = ...
            //      break;
            default:
                throw new Error(`Invalid chartId "${chartDescriptor.chartId}": render not found`);
        }
        this.render = () => renderFunction.call(this);
    }

    public get ctx() {
        return this._ctx;
    }

    public get data() {
        return this._data;
    }

    public get chart() {
        return this._chart;
    }

    public set chart(providedChart: Chart | undefined) {
        this._chart = providedChart;
    }

    fetchData(): void {
        this.xhr.open("GET", `/api/get/${this.dataTable}/${this.defaultDataQuantity}/`);
        this.xhr.send();
        this.xhr.addEventListener("load", () => {
            if (this.xhr.readyState === this.xhr.DONE) {
                if (this.xhr.status === 200) {
                    this._data = JSON.parse(this.xhr.responseText);
                    this._data.sort((a: EventDataEntry, b: EventDataEntry) => (a.epoch - b.epoch));
                    this.render();
                } else {
                    //TODO: message, erreur, 2n essai ?
                }
            }
        });
    }

    updateData(newData: EventDataEntry): void {
        this._data.push(newData);
        this.render();
    }
}