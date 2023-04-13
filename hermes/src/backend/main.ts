// Importation des modules nécessaires
import express, { Request, Response } from 'express'
import path from 'path'
import { sendSSEMessage } from './SSEClient';
import sqlite3 from 'sqlite3';

// const sqlite3 = require("sqlite3").verbose();

// Déclararation des variables 
const bodyParser = require('body-parser'); //TODO : Tester si ces libs sont nécessaires
const cors = require('cors'); // https://en.wikipedia.org/wiki/Cross-origin_resource_sharing

const app = express();
const port = 3000;
// const sqlQuery = "SELECT * FROM ? ORDER BY id DESC LIMIT ?;" // visiblement impossible d'utiliser cette méthode (avec une variable) somehow... :(

// Connexion à la bdd SQLite
let db = new sqlite3.Database('../data/journaux_simules.db', sqlite3.OPEN_READONLY, (err: Error | null) => {
	if (err) {
		console.error(err.message);
	}
	console.log('Connected to the database.');
});


app.use(cors());                                               // TODO : Tester si ces libs sont nécessaires
app.use(bodyParser.json());                                    // TODO : Tester si ces libs sont nécessaires
app.use(bodyParser.urlencoded({ extended: false }));           // TODO : Tester si ces libs sont nécessaires

app.use("/", express.static("build"));

// Racine du serveur
app.get("/", function (req: Request, res: Response) {
	res.sendFile(path.join(__dirname, "./build/index.html"));
});


app.get("/api/:table/:limit?/:reversed?", function (req: Request, res: Response) {
	console.log("API request params. :");
	console.dir(req.params);
	const regex = new RegExp("/^[A-Za-z]+$/");
	if (regex.test(req.params.table) && regex.test(req.params.limit)) { //TODO : limit n'est pas forcément définit donc f'faire gaffe 
		db.all(`SELECT * FROM ${req.params.table} ORDER BY id DESC LIMIT ${req.params.limit};`, [], function (err: Error | null, rows) { // /!\ éventuel injection SQL
			if (err) {
				throw err;
			}
			res.send(rows);
		});
	} else {
		// return an error
	}
});

// Reception des données des capteurs
// https://stackoverflow.com/questions/11625519/how-to-access-the-request-body-when-posting-using-node-js-and-express
app.post("/api/:table/:data", function (req: Request, res: Response) {
	console.log("API request params. :");
	console.dir(req.params);
	res.statusCode = 200;
	res.send()
})

// Flux SSE
app.get("/stream", function (req: Request, res: Response) {
	console.log("stream !")
	sendSSEMessage(res,); // TODO
})


// Lancement du serveur
app.listen(port, () => {
	console.log(`Hermes server launched: http://localhost:${port}`);
});