export type CubeFixationEntry = {
    epoch: number,
    fixe: number
}

export type CubePresenceEntry = {
    epoch: number,
    present: number
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

export type SQLDataEntry = CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry | ThresholdEntry | ConfigSettingEntry

export type SQLEventDataEntry = Exclude<SQLDataEntry, ThresholdEntry | ConfigSettingEntry>

export type SQLInfoDataEntry = Exclude<SQLDataEntry, CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry>

export type SQLDataset = SQLDataEntry[]

export type SQLEventDataset = SQLEventDataEntry[]

export type SQLInfoDataset = SQLInfoDataEntry[]