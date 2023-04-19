


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

// CREATE TABLE courant_moteur (
//     id INTEGER PRIMARY KEY,
//     valeur REAL,
//     horodatage TIMESTAMP DEFAULT (datetime('now','localtime'))
// );

export interface EngineCurrentEntry {
    id: number,
    valeur: number,
    horodatage: string
}

// CREATE TABLE blocages_moteur (
//     id INTEGER PRIMARY KEY,
//     horodatage TIMESTAMP DEFAULT (datetime('now','localtime'))
// );

export interface EngineBlockingEntry {
    id: number,
    fixe: boolean,
    horodatage: string
}

// CREATE TABLE seuils (
//     clef VARCHAR(32) PRIMARY KEY,
//     valeur INTEGER
// );

export interface ThresholdEntry {
    id: number,
    fixe: boolean,
    horodatage: string
}

// CREATE TABLE configuration (
//     clef VARCHAR(32) PRIMARY KEY,
//     valeur INTEGER
// );

export interface Entry {
    clef: string,
    valeur: number | string
}