const express = require("express");
const sqlite3 = require("sqlite3").verbose();
const path = require("path");

const app = express();
const port = 3000;
const sqlQuery = "SELECT * FROM ? ORDER BY id DESC LIMIT ?;"


let db = new sqlite3.Database('./data/journaux_simules.db', sqlite3.OPEN_READONLY, (err) => {
  if (err) {
    console.error(err.message);
  }
  console.log('Connected to the database.');
});


app.get("/", function(req, res) {
	res.sendFile(path.join(__dirname, "./build/index.html"));
});

app.get("/data/:table/:limit", function(req, res) {
	console.log("API request params. :");
	console.dir(req.params);
	db.all(`SELECT * FROM ${req.params.table} ORDER BY id DESC LIMIT ${req.params.limit};`, [], function(err, rows) {
		if (err) {
			throw err;
		}
		res.send(rows);
	});
});


app.use("/", express.static("build"));


app.listen(port, () => {
	console.log(`Hermes web server launched: http://localhost:${port} !`);
});