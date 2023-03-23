const sqlite3 = require("sqlite3").verbose();
const sql_query = "INSERT INTO ?(?) VALUES (?)";

var table;
var attributes;
var values;

let db = new sqlite3.Database("../db/journaux_simules.db", sqlite3.OPEN_READWRITE, (err) => {
    if (err) {
        console.error(err.message);
    }
    console.log("Connecté à la base de données");
});

function randInt(min, max) {
    /**
     * Retourne un nombre entier aléatoire entre `min` et `max`
     * @param  {number} min - Valeur aléatoire minimum
     * @param {number} max - Valeur aléatoire maximum
     * @returns {number}
     */
    return Math.floor(Math.random() * (max + 1 - min) + min);
}


function addRecord(table, attributes, values) {
    db.run(sql_query, [table, attributes, values], (err) => {
        if (err) {
            console.error(err);
        }
        console.log(`[+] ${table} => ${attributes} : ${values}`)
    });
}


setInterval(() => {
    // fixation plateau 
    if (randInt(0, 4) === 0) {
        table = "fixation_plateau";
        attributes = "fixe";
        values = randInt(0, 1);
        addRecord(table, attributes, valeurs)
    }

    // presence plateau
    if (randInt(0, 4) === 0) {
        table = "presence_plateau";
        attributs = ;
        valeur = ;
        addRecord(table, attributes, valeurs)
    }


    // courant moteur
    if (randInt(0, 4) === 0) {
        table = "courant_moteur";
        attributs = "";
        valeur = ;
        addRecord(table, attributes, valeurs)
    }

    // blocages moteur
    if (randInt(0, 4) === 0) {
        table = "blocages_moteur";
        attributs = ;
        valeur = ;
        addRecord(table, attributes, valeurs)
    }

    // seuils
    if (randInt(0, 4) === 0) {
        table = "seuils";
        attributs = ;
        valeur = ;
        addRecord(table, attributes, valeurs)
    }

    // configuration
    if (randInt(0, 4) === 0) {
        table = "configuration";
        attributs = ;
        valeur = ;
        addRecord(table, attributes, valeurs)
    }

}, 1000)