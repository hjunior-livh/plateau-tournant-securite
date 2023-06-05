/**
 * 
 */
export type ChartDescriptor = {
    chartId: string,
    HTMLElementId: string,
    dataType: "sqlite" | "csv",
} & (
    {
        dataTable: string,
        defaultDataQuantity: number
    } | {
        filename: string
    }
)


export const CHART_DESCRIPTORS: ChartDescriptor[] = [
    {
        chartId: "engine-current",
        HTMLElementId: "engineCurrentChart",
        dataType: "csv",
        dataTable: "courant_moteur",
        defaultDataQuantity: 1000
    }
    //...
];