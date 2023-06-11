import type { Chart } from "../lib/chart.js/dist/types/index.js"
import type { ChartDescriptor } from "../types/ChartDescriptors.js";


export class BaseChart {

    protected id: string;
    protected HTMLElementId: string;
    protected chartTitle: string;
    protected dataLegend: string;
    protected canvas: HTMLCanvasElement | null;
    protected ctx: CanvasRenderingContext2D;
    protected data?: unknown;
    protected chart?: Chart;
    protected xhr: XMLHttpRequest;

    constructor(descriptor: ChartDescriptor) {
        this.id = descriptor.chartId;
        this.HTMLElementId = descriptor.HTMLElementId;
        this.chartTitle = descriptor.chartTitle;
        this.dataLegend = descriptor.dataLegend;
        this.canvas = document.getElementById(this.HTMLElementId) as HTMLCanvasElement;
        if (this.canvas === null) {
            throw new Error("Invalid canvasID");
        }
        this.ctx = this.canvas.getContext("2d") as CanvasRenderingContext2D;
        if (this.ctx === null) {
            throw new Error("Unable to get 2D context");
        }
        this.data = [];
        this.xhr = new XMLHttpRequest();
    }

    // Peut être faire la même chose avec le fetchData qu'avec la method render
    // Faire du error handling sur les requetes de csv
    // utiliser la requete de csv générique pour les csv de courants
    // struct avec la localisation de /types/ et les options de trabspilation/compilation

    // abstract render(): void;
    // abstract fetchData(): void;
    // abstract updateData(): void;
}