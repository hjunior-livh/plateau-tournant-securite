import type { DataEntry } from "./DatabaseTypes.js"

export type StreamMessage = {
    table: string
    entry: DataEntry
}