// const routes = require("./routes.js")
const express = require('express')
const app = express()
var bcrypt = require('bcryptjs');
const port = 3000
app.use(express.json())

const mysql = require('mysql2');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    database: "Poodle"
});

con.connect(function(err) {
    if (err) throw err;
    console.log("Connected to the database!");
});

require('./routes')(app, con, bcrypt)

app.listen(port, () => {
    console.log("Server listening on port 3000")})