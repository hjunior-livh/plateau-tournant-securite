import { ChartDisplay } from "../ChartDisplay.js";

export interface ChartRenderer {
    (this: ChartDisplay): void;
}