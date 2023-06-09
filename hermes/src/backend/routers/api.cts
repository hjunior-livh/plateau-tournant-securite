import { Router, Request, Response } from 'express';
import { StreamSubscriberPool } from '../classes/StreamSubscriberPool.cjs'
import { parseCSV } from '../utils/parseCSV.cjs';
import sqlite3 from 'sqlite3';
import fs from 'fs';


const apiRouter: Router = Router();
const TableParamRegex: RegExp = new RegExp(/^[A-Za-z_]+$/);
const QuantityParamRegex: RegExp = new RegExp(/^\d{1,5}$/)
const streamSubscribers: StreamSubscriberPool = new StreamSubscriberPool();
let argTable: string;
let argQuantity: number;

const db = new sqlite3.Database('./data/simulated_data.db', sqlite3.OPEN_READONLY, (err: Error | null) => {
	if (err) {
		throw err;
	}
	console.log('[i] Connected to the database.');
});


// API: send SQLite data to client
apiRouter.get("/table/:table/:quantity/", (req: Request, res: Response) => {
	argTable = req.params.table;
	argQuantity = parseInt(req.params.quantity, 10);

	if (isNaN(argQuantity)) {
		res.status(400).send({ "error": "Invalid 'quantity' argument (Integer parsing failed)" })
	}

	else if (TableParamRegex.test(argTable) && QuantityParamRegex.test(argQuantity.toString())) {
		db.all(`SELECT * FROM ${argTable} ORDER BY epoch DESC LIMIT ${argQuantity};`, [], (err: Error | null, rows: unknown[]) => {
			if (err) {
				throw err;
			}
			res.send(rows);
		});
	} else {
		res.status(400).send({ "error": "Invalid arguments (Regex check failed)" });
	}
});


// API: data 
apiRouter.get("/csv/:filename/", (req: Request, res: Response) => {
	parseCSV(req.params.filename)
		.then((data) => {
			res.send(data)
		})
		.catch((error) => {
			console.error('Error reading/parsing CSV:', error);
		});
})


// API: data reception
apiRouter.post("/table/:table/", (req: Request, res: Response) => {
	console.log(`[+] New data incoming: TABLE=${req.params.table}`);
	res.status(200).end();
	streamSubscribers.sendEvent("new_data", req.params.table, req.body);
});


// API: SSE stream
apiRouter.get("/stream/", (req: Request, res: Response) => {
	streamSubscribers.addSubscriber(res);
});


// API: CSV Rotation files
apiRouter.get("/get-rotation-files/", (req: Request, res: Response) => {
	const filenames = fs.readdirSync("./data/engine-current/");
	res.send(JSON.stringify(filenames)); 
})


// API: CSV Rotation file
apiRouter.get("/get-rotation-file/:filename/", (req: Request, res: Response) => {
	const filenames = fs.
	res.send(JSON.stringify(filenames)); 
})


export { apiRouter }