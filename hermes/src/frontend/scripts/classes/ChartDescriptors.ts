import { ChartDescriptor } from "../types/ChartDescriptors.js";
import { engineCurrentRenderer } from "./components/engineCurrentRenderer.js";


export const CHART_DESCRIPTORS: ChartDescriptor[] = [
    {
        chartId: "engine-current",
        HTMLElementId: "engineCurrentChart",
        renderFunction: engineCurrentRenderer,
        dataType: "csv",
        filename: "releve.csv"
    }
    //...
];