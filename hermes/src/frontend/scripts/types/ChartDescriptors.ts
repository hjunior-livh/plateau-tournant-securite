import type { ChartDisplay } from "../classes/ChartDisplay.js"

export type BaseChartDescriptor = {
    chartId: string,
    HTMLElementId: string,
    dataType: "sql" | "csv"
    renderFunction: (this: ChartDisplay) => void 
}

export type SQLChartDescriptor = BaseChartDescriptor & {
    dataType: "sql"
    dataTable: string,
    defaultDataQuantity: number
}

export type CSVChartDiscriptor = BaseChartDescriptor & {
    dataType: "csv"
    filename: string
}

export type ChartDescriptor =  SQLChartDescriptor | CSVChartDiscriptor