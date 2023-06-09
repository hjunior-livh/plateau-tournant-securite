import type { Chart, ChartItem } from "../lib/chart.js/dist/types/index.js"
import type { EventDataEntry, EventDataset } from "../types/DatabaseTypes.js";
import type { ChartDescriptor, SQLChartDescriptor, CSVChartDiscriptor } from "../types/ChartDescriptors.js";
import type { ChartRenderer } from "../types/ChartRenderInterface.js";


export class ChartDisplay {

    public render: ChartRenderer;
    public readonly id: string;
    public readonly dataType: string;
    public readonly dataTable?: string;

    private _HTMLElementId: string;
    private _defaultDataQuantity?: number;
    private _filename?: string;
    private _canvas: HTMLCanvasElement | null;
    private _ctx: ChartItem;
    private _data: EventDataset;
    private _chart?: Chart;
    private _xhr: XMLHttpRequest;

    constructor(descriptor: ChartDescriptor) {
        this.id = descriptor.chartId;
        this.dataType = descriptor.dataType;
        this._HTMLElementId = descriptor.HTMLElementId;
        this._canvas = document.getElementById(this._HTMLElementId) as (HTMLCanvasElement | null); // !!!
        if (this._canvas === null) {
            throw new Error("Invalid canvasID");
        }
        this._ctx = this._canvas.getContext("2d") as ChartItem;
        if (this._ctx === null) {
            throw new Error("Unable to get 2D context");
        }
        this._data = [];
        this._xhr = new XMLHttpRequest();

        switch (descriptor.dataType) {
            case "sql":
                this.dataTable = descriptor.dataTable;
                this._defaultDataQuantity = descriptor.defaultDataQuantity;
                break;
            case "csv":
                this._filename = descriptor.filename
                break;
        }

        this.render = descriptor.renderFunction
        this.render()
    }

    // Peut être faire la même chose avec le fetchData qu'avec la method render
    // Faire du error handling sur les requetes de csv
    // utiliser la requete de csv générique pour les csv de courants
    // struct avec la localisation de /types/ et les options de trabspilation/compilation

    public get ctx() {
        return this._ctx;
    }

    public get data() {
        return this._data;
    }

    public get chart(): Chart | undefined {
        return this._chart;
    }

    public set chart(chart: Chart | undefined) {
        this._chart = chart;
    }

    fetchData(): void {
        this._xhr.open("GET", `/api/table/${this.dataTable}/${this._defaultDataQuantity}/`);
        this._xhr.send();
        this._xhr.addEventListener("load", () => {
            if (this._xhr.readyState === this._xhr.DONE) {
                if (this._xhr.status === 200) {
                    this._data = JSON.parse(this._xhr.responseText);
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