/**
 * 
 */
export type ChartDescriptor = {
    chartId: string,
    HTMLElementId: string,
    dataTable: string,
    defaultDataQuantity: number
}


export const CHART_DESCRIPTORS: ChartDescriptor[] = [
    {
        chartId: "engine-current",
        HTMLElementId: "engineCurrentChart",
        dataTable: "courant_moteur",
        defaultDataQuantity: 1000
    }
    //...
];