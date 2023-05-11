const sqlite3 = require("sqlite3").verbose();

var table;
var attributes;
var values;

let db = new sqlite3.Database("../data/simulated_data.db", sqlite3.OPEN_READWRITE, (err) => {
    if (err) {
        console.error(err.message);
    }
    console.log("Connecté à la base de données");
});


function randInt(min, max) {
    return Math.floor(Math.random() * (max + 1 - min) + min);
}


function randFloat(min, max) {
    return Math.random() * (max - min) + min;
}


function addRecord(table, attributes, values) {

    db.run(`INSERT INTO ${table}(${attributes}) VALUES (${values});`, [], (err) => {
        if (err) {
            console.error(err);
        }
        console.log(`[+] ${table}: ${attributes} ➜ ${values}`);
    });
}


setInterval(() => {
    // fixation plateau 
    if (randInt(0, 5) === 0) {
        table = "fixation_cube";
        attributes = "fixe";
        values = randInt(0, 1);
        addRecord(table, attributes, values);
    }

    //presence plateau
    if (randInt(0, 5) === 0) {
        table = "presence_cube";
        attributes = "present";
        values = randInt(0, 1);
        addRecord(table, attributes, values);
    }


    //courant moteur
    if (randInt(0, 1) === 0) {
        table = "courant_moteur";
        attributes = "valeur";
        values = randFloat(0.3, 1);
        addRecord(table, attributes, values);
    }

    //blocages moteur
    if (randInt(0, 20) === 0) {
        table = "blocages_moteur";
        attributes = "";
        values = "";
        addRecord(table, attributes, values);
    }

    //seuils
    // if (randInt(0, 4) === 0) {
    //     table = "seuils";
    //     attributes = null;
    //     values = null;
    //     addRecord(table, attributes, values);
    // }

    //configuration
    // if (randInt(0, 4) === 0) {
    //     table = "configuration";
    //     attributes = ;
    //     values = ;
    //     addRecord(table, attributes, values);
    // }

}, 1000)