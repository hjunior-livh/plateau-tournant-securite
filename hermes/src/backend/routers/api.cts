import { Router, Request, Response } from 'express';
import { StreamSubscriberPool } from '../utils/StreamSubscriberPool.cjs'
import sqlite3 from 'sqlite3';


const apiRouter: Router = Router();
const SQLParamRegex: RegExp = new RegExp(/^[A-Za-z_]+$/);
const streamSubscribers: StreamSubscriberPool = new StreamSubscriberPool();
let argTable: string;
let argQuantity: number;

const db = new sqlite3.Database('./data/simulated_data.db', sqlite3.OPEN_READONLY, (err: Error | null) => {
	if (err) {
		throw err;
	}
	console.log('[i] Connected to the database.');
});


// API: send data to client
apiRouter.get("/get/:table/:quantity/", (req: Request, res: Response) => {
	argTable = req.params.table;
	argQuantity = parseInt(req.params.quantity, 10);
	if (isNaN(argQuantity)) {
		res.status(400).send({"error": "Invalid 'quantity' argument (Integer parsing failed)"})
	}

	if (SQLParamRegex.test(argTable)) { //TODO : limit n'est pas forcément définit donc f'faire gaffe 
		db.all(`SELECT * FROM ${argTable} ORDER BY epoch DESC LIMIT ${argQuantity};`, [], (err: Error | null, rows: unknown[]) => { // /!\ éventuel injection SQL
			if (err) {
				throw err;
			}
			res.send(rows);
		});
	} else {
		res.status(400).send({"error": "Invalid arguments (Regex check failed)"});
	}
});


// API: data reception
apiRouter.post("/post/:table/", (req: Request, res: Response) => {
	console.log(`[+] New data incoming: TABLE=${req.params.table}`);
	res.status(200).end();
	streamSubscribers.sendEvent("new_data", req.params.table, req.body);
});


// SSE stream
apiRouter.get("/stream/", (req: Request, res: Response) => {
	streamSubscribers.addSubscriber(res);
});


export { apiRouter }