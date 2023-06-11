export type BaseChartDescriptor = {
    chartId: string,
    HTMLElementId: string,
    chartTitle: string,
    dataLegend: string
}

export type SQLChartDescriptor = BaseChartDescriptor & {
    dataType: "sql"
    dataTable: string,
    defaultDataQuantity: number
}

export type CSVChartDiscriptor = BaseChartDescriptor & {
    dataType: "csv",
    filename: string
}

export type ChartDescriptor = SQLChartDescriptor | CSVChartDiscriptor

export const CHART_DESCRIPTORS: ChartDescriptor[] = [
    {
        chartId: "engine-current",
        HTMLElementId: "engineCurrentChart",
        chartTitle: "Courant moteur",
        dataLegend: "Courant du moteur relevé par le capteur",
        dataType: "csv",
        filename: "releve.csv"
    }
];