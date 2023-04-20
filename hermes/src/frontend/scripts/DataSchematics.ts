export interface CubeFixationEntry {
    id: number,
    fixe: boolean,
    horodatage: string
}

export interface CubePresenceEntry {
    id: number,
    present: boolean,
    horodatage: string
}

export interface EngineCurrentEntry {
    id: number,
    valeur: number,
    horodatage: string
}

export interface EngineBlockingEntry {
    id: number,
    horodatage: string
}

export interface ThresholdEntry {
    clef: string,
    valeur: number
}

export interface ConfigSettingEntry {
    clef: string,
    valeur: string
}

export interface Dataset extends Array<CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry | ThresholdEntry | ConfigSettingEntry> {
    [index: number]: CubeFixationEntry | CubePresenceEntry | EngineCurrentEntry | EngineBlockingEntry | ThresholdEntry | ConfigSettingEntry;
}