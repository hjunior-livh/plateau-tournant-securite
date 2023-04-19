export const CHART_ENGINE_CURRENT: number = 0;
// export const CHART_ENGINE_CURRENT: number = 0;
// ...


export interface ChartDescriptor {
    HTMLElementId: string,
    dataTable: string,
    defaultDataQuantity: number
}


export const chartDescriptors: ChartDescriptor[] = [
    {
        HTMLElementId: "engineCurrentChart",
        dataTable: "courant_moteur",
        defaultDataQuantity: 10
    }
    //...
];
