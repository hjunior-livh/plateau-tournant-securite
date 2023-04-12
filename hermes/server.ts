import express, {Request, Response, NextFunction} from 'express'
import path from 'path'
const sqlite3 = require("sqlite3").verbose();


const bodyParser = require('body-parser');
const cors = require('cors');

const app = express();
const port = 3000;
// const sqlQuery = "SELECT * FROM ? ORDER BY id DESC LIMIT ?;" // visiblement impossible d'utiliser cette méthode (avec une variable) somehow... :(


let db = new sqlite3.Database('./data/journaux_simules.db', sqlite3.OPEN_READONLY, (err) => {
  if (err) {console.error(err.message);}
  console.log('Connected to the database.');
});


app.use(cors());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: false}));
app.use("/", express.static("build"));


app.get("/", function(req: Request, res: Response) {
	res.sendFile(path.join(__dirname, "./build/index.html"));
});


app.get("/api/:table/:limit?", function(req: Request, res: Response) {
	console.log("API request params. :");
	console.dir(req.params);
	const regex = new RegExp("/^[A-Za-z]+$/");
	if (regex.test(req.params.table) && regex.test(req.params.limit)) { //TODO : limit n'est pas forcément définit donc f'faire gaffe 
		db.all(`SELECT * FROM ${req.params.table} ORDER BY id DESC LIMIT ${req.params.limit};`, [], function(err, rows) {
			if (err) {
				throw err;
			}
			res.send(rows);
		});
	} else {
		// return an error
	}
});

app.post("/api/:table/:data", function(req: Request, res: Response) {
	console.log("API request params. :");
	console.dir(req.params);
	res.statusCode = 200;
	res.send()
})

app.get("/stream", function(req: Request, res: Response) {
	console.log("stream !")
	const headers = {
		'Content-Type': 'text/event-stream',
		'Connection': 'keep-alive',
		'Cache-Control': 'no-cache'
	};

	res.writeHead(200, headers);
	res.write("hello, world!");
})


app.listen(port, () => {
	console.log(`Hermes server launched: http://localhost:${port} !`);
});