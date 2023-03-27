/* 
JOURNAUX
========================

# "fixation_plateau" 
# => Repertorie l'historique de l'état de fixation du cube
    - id* (ENTIER) : identifiant unique
    - fixe (ENTIER) :
    - horodatage (DATE) : horodatage automatique de la saisie de la ligne

# "presence plateau"
# => Repertorie l'historique de la présence du cube
    - id* (ENTIER) : identifiant unique
    - present (ENTIER) : 
    - horodatage (DATE) : horodatage automatique de la saisie de la ligne

# "consignes"
# => Repertorie les seuils
    - clef* (TEXTE[32]) : 
    - valeur (ENTIER) : 

# "configuration"
# => Repertorie les valeurs de configuration
    - clef* (TEXTE[32]) :
    - valeur (ENTIER) : 

------------------------
* : clef primaire  

*/

-- DROP TABLE fixation_plateau;
-- DROP TABLE presence_plateau;
-- DROP TABLE courant_moteur;
-- DROP TABLE blocages_moteur;
-- DROP TABLE seuils;
-- DROP TABLE configuration;


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

CREATE TABLE blocages_moteur (
    id INTEGER PRIMARY KEY,
    horodatage TIMESTAMP DEFAULT (datetime('now','localtime'))
);

CREATE TABLE seuils (
    clef VARCHAR(32) PRIMARY KEY,
    valeur INTEGER
);

CREATE TABLE configuration (
    clef VARCHAR(32) PRIMARY KEY,
    valeur INTEGER
);