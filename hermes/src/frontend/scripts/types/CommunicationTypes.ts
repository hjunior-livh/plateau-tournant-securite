import { DataEntry } from "./DatabaseTypes.js"

export type StreamMessage = {
    table: string
    entry: DataEntry
}