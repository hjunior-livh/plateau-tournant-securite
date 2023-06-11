import type { SQLDataEntry } from "./SQLDatabaseTypes.js"

export type StreamMessage = {
    table: string
    entry: SQLDataEntry
}