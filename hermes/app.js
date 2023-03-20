const express = require("express");
const sqlite3 = require("sqlite3").verbose();
const path = require("path");

const app = express();
const port = 3000;

let db = new sqlite3.Database('./db/logs.db', sqlite3.OPEN_READONLY, (err) => {
  if (err) {
    console.error(err.message);
  }
  console.log('Connected to the database.');
});

app.get("/", function(req, res) {
	res.sendFile(path.join(__dirname, "/public/html/index.html"));
});

app.get("/data", function(req, res) {
	db.all("SELECT * FROM journal_fixation", [], function(err, rows) {
		if (err) {
			throw err;
		}
		console.log(rows);}
	);
});

app.use("/static", express.static("public"))

app.listen(port, () => {
	console.log(`Hermes launched: http://localhost:${port}!`);
});