CREATE TABLE fixation_cube (
    id INTEGER PRIMARY KEY,
    fixe INTEGER,                                  
    horodatage TIMESTAMP DEFAULT (datetime('now','localtime'))
);

CREATE TABLE presence_cube (
    id INTEGER PRIMARY KEY,
    present INTEGER,
    horodatage TIMESTAMP DEFAULT (datetime('now','localtime'))
);

CREATE TABLE courant_moteur (
    id INTEGER PRIMARY KEY,
    valeur REAL,
    horodatage TIMESTAMP DEFAULT (datetime('now','localtime'))
);

CREATE TABLE blocage_moteur (
    id INTEGER PRIMARY KEY,
    horodatage TIMESTAMP DEFAULT (datetime('now','localtime'))
);

CREATE TABLE seuil_capteur (
    clef VARCHAR(32) PRIMARY KEY,
    valeur INTEGER
);

CREATE TABLE paramètre_configuration (
    clef VARCHAR(32) PRIMARY KEY,
    valeur INTEGER
);