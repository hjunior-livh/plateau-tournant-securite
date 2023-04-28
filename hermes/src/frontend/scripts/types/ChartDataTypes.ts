export type CubeFixationEntry = {
    id: number,
    fixe: boolean,
    horodatage: string
}

export type CubePresenceEntry = {
    id: number,
    present: boolean,
    horodatage: string
}

export type EngineCurrentEntry = {
    id: number,
    valeur: number,
    horodatage: string
}

export type EngineBlockingEntry = {
    id: number,
    horodatage: string
}

export type ThresholdEntry = {
    clef: string,
    valeur: number
}

export type ConfigSettingEntry = {
    clef: string,
    valeur: string
}

export type Dataset = Array<CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry | ThresholdEntry | ConfigSettingEntry> & {
    [index: number]: CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry | ThresholdEntry | ConfigSettingEntry;
}