export interface ChartDescriptor {
    chartId: string,
    HTMLElementId: string,
    dataTable: string,
    defaultDataQuantity: number
}


export const chartDescriptors: ChartDescriptor[] = [
    {
        chartId: "engine-current",
        HTMLElementId: "engineCurrentChart",
        dataTable: "courant_moteur",
        defaultDataQuantity: 10
    }
    //...
];
