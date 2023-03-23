const express = require("express");
const sqlite3 = require("sqlite3").verbose();
const path = require("path");

const app = express();
const port = 3000;

var sql_query = `SELECT * FROM ? order by id desc limit ?;`

let db = new sqlite3.Database('./db/journaux_simules.db', sqlite3.OPEN_READONLY, (err) => {
  if (err) {
    console.error(err.message);
  }
  console.log('Connected to the database.');
});

app.get("/", function(req, res) {
	res.sendFile(path.join(__dirname, "/public/html/index.html"));
});

app.get("/donnees/:table/:qte", function(req, res) {
	console.log(req.params);
	// db.all(, [], function(err, rows) {
	// 	if (err) {
	// 		throw err;
	// 	}
	// 	console.log(rows);}
	// );
});

app.use("/static", express.static("public"))

app.listen(port, () => {
	console.log(`Hermes launched: http://localhost:${port}!`);
});