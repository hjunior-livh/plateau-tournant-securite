import { SQLChart } from "./SQLChart.js";
import { CSVChart } from "./CSVChart.js";
import type { ChartDescriptor } from "../types/ChartDescriptors.js";


export class ChartFactory {
    produceChart(descriptor: ChartDescriptor) {
        switch (descriptor.dataType) {
            case "sql":
                return new SQLChart(descriptor);
            case "csv":
                return new CSVChart(descriptor)
        }
    }
}