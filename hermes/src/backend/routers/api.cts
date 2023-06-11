import { Router, Request, Response } from 'express';
import { StreamSubscriberPool } from '../classes/StreamSubscriberPool.cjs'
import { parseCSV } from '../utils/parseCSV.cjs';
import sqlite3 from 'sqlite3';
import fs from 'fs';


const apiRouter: Router = Router();
const TableParamRegex: RegExp = new RegExp(/^[A-Za-z_]+$/);
const QuantityParamRegex: RegExp = new RegExp(/^\d{1,5}$/);
const engineCurrentFileRegex: RegExp = new RegExp(/^releves_.*\.csv$/);
const streamSubscribers: StreamSubscriberPool = new StreamSubscriberPool();
let argTable: string;
let argQuantity: number;

const db = new sqlite3.Database('./data/simulated_data.db', sqlite3.OPEN_READONLY, (err: Error | null) => {
	if (err) {
		throw err;
	}
	console.log('[i] Connected to the database.');
});


// Send SQLite data to client
apiRouter.get("/table/:table/:quantity/", (req: Request, res: Response) => {
	argTable = req.params.table;
	argQuantity = parseInt(req.params.quantity, 10);

	if (isNaN(argQuantity)) {
		res.send({ "error": "Invalid 'quantity' argument (Integer parsing failed)" }).status(400);
	}

	else if (TableParamRegex.test(argTable) && QuantityParamRegex.test(argQuantity.toString())) {
		db.all(`SELECT * FROM ${argTable} ORDER BY epoch DESC LIMIT ${argQuantity};`, [], (err: Error | null, rows: unknown[]) => {
			if (err) {
				throw err;
			}
			res.send(rows);
		});
	} else {
		res.send({ "error": "Invalid arguments (Regex check failed)" }).status(400);
	}
});


// Send CSV data to the client
apiRouter.get("/csv/:folder/:filename/", (req: Request, res: Response) => {
	parseCSV(`${req.params.folder}/${req.params.filename}`)
		.then((data) => {
			res.send(data).end();
		})
		.catch((error) => {
			console.error('Error reading/parsing CSV:', error);
			res.send({ "error": "Error reading/parsing CSV" }).status(400);
		});
})


// Data reception
apiRouter.post("/table/:table/", (req: Request, res: Response) => {
	console.log(`[+] New data incoming: TABLE=${req.params.table}`);
	res.status(200).end();
	streamSubscribers.sendEvent("new_data", req.params.table, req.body);
});


// SSE stream
apiRouter.get("/stream/", (req: Request, res: Response) => {
	streamSubscribers.addSubscriber(res);
});


// CSV Rotation files
apiRouter.get("/get-rotation-files/", (req: Request, res: Response) => {
	let filenames = fs.readdirSync("./data/engine-current/");
	filenames = filenames.filter((filename: string) => engineCurrentFileRegex.test(filename));
	res.send(JSON.stringify(filenames)).end();;
})


export { apiRouter }