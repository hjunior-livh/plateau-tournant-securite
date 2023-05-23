-- Table: fixation_cube
-- Desc.: 
-- Prop.: 
--       * epoch : INTEGER
--       * fixe : INTEGER


-- Table: presence_cube
-- Desc.: 
-- Prop.: 
--       * epoch : INTEGER
--       * fixe : INTEGER


-- Table: courant_moteur
-- Desc.: 
-- Prop.:
--       * epoch : INTEGER
--       * valeur : INTEGER


-- Table: blocage_moteur
-- Desc.: 
-- Prop.: 
--       * epoch : INTEGER


-- Table: seuil_capteur
-- Desc.: 
-- Prop.: 
--       * clef : VARCHAR(32)
--       * valeur : INTEGER


-- Table: paramètre_configuration
-- Desc.: 
-- Prop.: 
--       * clef : VARCHAR(32)
--       * valeur : INTEGER


CREATE TABLE fixation_cube (
    epoch INTEGER PRIMARY KEY,
    fixe INTEGER                         
);

CREATE TABLE presence_cube (
    epoch INTEGER PRIMARY KEY,
    present INTEGER
);

CREATE TABLE courant_moteur (
    epoch INTEGER PRIMARY KEY,
    valeur INTEGER
);

CREATE TABLE blocage_moteur (
    epoch INTEGER PRIMARY KEY
);

CREATE TABLE seuil_capteur (
    clef VARCHAR(32) PRIMARY KEY,
    valeur INTEGER
);

CREATE TABLE paramètre_configuration (
    clef VARCHAR(32) PRIMARY KEY,
    valeur INTEGER
);