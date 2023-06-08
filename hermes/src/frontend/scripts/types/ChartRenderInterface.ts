import type { ChartDisplay } from "../classes/ChartDisplay.js";

export interface ChartRenderer {
    (this: ChartDisplay): void;
}