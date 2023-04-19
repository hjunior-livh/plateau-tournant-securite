// Importation des modules nécessaires
import express, { Request, Response } from 'express'
import path from 'path'
import { StreamSubscriberPool } from './StreamSubscriberPool';
import sqlite3 from 'sqlite3';


// Déclararation des variables 
const app = express();
const port = 3000;
const SQLParamRegex = new RegExp(/^[A-Za-z_]+$/);
const streamSubscribers: StreamSubscriberPool = new StreamSubscriberPool();
let argTable: string;
let argQuantity: number;
let argReversed: boolean;


// "Connexion" à la bdd SQLite
const db = new sqlite3.Database('./data/journaux_simules.db', sqlite3.OPEN_READONLY, (err: Error | null) => {
	if (err) {
		throw err;
	}
	console.log('[i] Connected to the database.');
});


// Utilisation des middlewares
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use("/", express.static("./build/public"));


// Racine du serveur
app.get("/", function (req: Request, res: Response) {
	res.sendFile(path.join(__dirname, "./public/index.html"));
});


// API: envoi des données au client
app.get("/api/:table/:quantity/", function (req: Request, res: Response) {
	console.log("[i] API request params. :");
	console.dir(req.params);

	argTable = req.params.table;
	argQuantity = parseInt(req.params.quantity, 10);
	if (isNaN(argQuantity)) {
		res.status(400).send({"error": "Invalid 'quantity' argument (Integer parsing failed)"})
	}
	if (req.params.reversed === undefined) {
		argReversed = false;
	} else {
		argReversed = req.params.reversed === "true"; // sujet à des pb: false sera retourné si c'est ni 'true' ni 'false'
	}

	if (SQLParamRegex.test(argTable)) { //TODO : limit n'est pas forcément définit donc f'faire gaffe 
		db.all(`SELECT * FROM ${argTable} ORDER BY id DESC LIMIT ${argQuantity};`, [], function (err: Error | null, rows) { // /!\ éventuel injection SQL
			if (err) {
				throw err;
			}
			res.send(rows);
		});
	} else {
		res.status(400).send({"error": "Invalid arguments (Regex check failed)"});
	}
});


// API: reception des données
app.post("/api/:table/", function (req: Request, res: Response) {
	console.log("API request params. :");
	console.dir(req.params);
	streamSubscribers.sendEvent("new_data", req.body);
})


// Flux SSE
app.get("/stream/", function (req: Request, res: Response) {
	console.log("[+] New stream subscribers");
	streamSubscribers.addSubscriber(res);
})


// Lancement du serveur
app.listen(port, () => {
	console.log(`[i] Hermes server launched: http://localhost:${port}`);
});