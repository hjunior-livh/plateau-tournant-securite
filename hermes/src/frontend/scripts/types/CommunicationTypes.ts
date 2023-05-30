import { DataEntry } from "./DatabaseTypes"

export type StreamMessage = {
    table: string
    entry: DataEntry
}