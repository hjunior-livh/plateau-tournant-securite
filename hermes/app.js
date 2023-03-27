const express = require("express");
const sqlite3 = require("sqlite3").verbose();
const path = require("path");

const app = express();
const port = 3000;

var sql_query = `SELECT * FROM ? order by id desc limit ?;`

let db = new sqlite3.Database('./data/journaux_simules.db', sqlite3.OPEN_READONLY, (err) => {
  if (err) {
    console.error(err.message);
  }
  console.log('Connected to the database.');
});

app.get("/", function(req, res) {
	res.sendFile(path.join(__dirname, "/public/html/index.html"));
});

app.get("/data/:table/:quantity", function(req, res) {
	console.log(`API request params. : ${req.params}`);
	db.all(`SELECT * FROM ${req.params.table} order by id desc limit ${req.params.quantity};`, [], function(err, rows) {
		if (err) {
			throw err;
		}
		res.send(rows);
	});
});

app.use("/static", express.static("public"))

app.listen(port, () => {
	console.log(`Hermes launched: http://localhost:${port}!`);
});