export type CubeFixationEntry = {
    epoch: number,
    fixe: boolean
}

export type CubePresenceEntry = {
    epoch: number,
    present: boolean
}

export type EngineCurrentEntry = {
    epoch: number,
    valeur: number
}

export type EngineBlockingEntry = {
    epoch: number
}

export type ThresholdEntry = {
    clef: string,
    valeur: number
}

export type ConfigSettingEntry = {
    clef: string,
    valeur: string
}

export type DataEntry = CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry | ThresholdEntry | ConfigSettingEntry;

export type StreamMessage = {
    table: string
    entry: DataEntry
}

export type Dataset = DataEntry[];