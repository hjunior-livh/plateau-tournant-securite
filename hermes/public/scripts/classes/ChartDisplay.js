"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.ChartDisplay = void 0;
const engineCurrentRenderer_1 = require("./components/engineCurrentRenderer");
class ChartDisplay {
    constructor(chartDescriptor) {
        let renderFunction;
        this.id = chartDescriptor.chartId;
        this.HTMLElementId = chartDescriptor.HTMLElementId;
        this.dataTable = chartDescriptor.dataTable;
        this.defaultDataQuantity = chartDescriptor.defaultDataQuantity;
        this.canvas = document.getElementById(this.HTMLElementId); // !!!
        if (this.canvas === null) {
            throw new Error("Invalid canvasID");
        }
        this._ctx = this.canvas.getContext("2d");
        if (this._ctx === null) {
            throw new Error("Unable to get 2D context");
        }
        this._data = [];
        this.xhr = new XMLHttpRequest();
        switch (chartDescriptor.chartId) {
            case "engine-current":
                renderFunction = engineCurrentRenderer_1.engineCurrentRenderer;
                break;
            // case "...":
            //     module = ...
            //      break;
            default:
                throw new Error(`Invalid chartId "${chartDescriptor.chartId}": render not found`);
        }
        this.render = () => renderFunction.call(this);
    }
    get ctx() {
        return this._ctx;
    }
    get data() {
        return this._data;
    }
    get chart() {
        return this._chart;
    }
    set chart(providedChart) {
        this._chart = providedChart;
    }
    fetchData() {
        this.xhr.open("GET", `/api/get/${this.dataTable}/${this.defaultDataQuantity}/`);
        this.xhr.send();
        this.xhr.addEventListener("load", () => {
            if (this.xhr.readyState === this.xhr.DONE) {
                if (this.xhr.status === 200) {
                    this._data = JSON.parse(this.xhr.responseText);
                    this._data.sort((a, b) => (a.epoch - b.epoch));
                    this.render();
                }
                else {
                    //TODO: message, erreur, 2n essai ?
                }
            }
        });
    }
    updateData(newData) {
        this._data.push(newData);
        this.render();
    }
}
exports.ChartDisplay = ChartDisplay;
