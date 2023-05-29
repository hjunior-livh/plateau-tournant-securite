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


export type DataEntry = CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry | ThresholdEntry | ConfigSettingEntry

export type EventDataEntry = Exclude<DataEntry, ThresholdEntry | ConfigSettingEntry>

export type InfoDataEntry = Exclude<DataEntry, CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry>

export type Dataset = Array<DataEntry>

export type EventDataset = EventDataEntry[]

export type InfoDataset = InfoDataEntry[]