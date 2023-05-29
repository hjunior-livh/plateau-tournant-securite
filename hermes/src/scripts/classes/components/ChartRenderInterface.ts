import { ChartDisplay } from "../ChartDisplay";

export interface ChartRenderer {
    (this: ChartDisplay): void;
}