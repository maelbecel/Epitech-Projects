const express = require('express')
const app = express()
const crypto = require('crypto');
const auth = require('./middleware');
const authTokens = {};
var jwt = require('jsonwebtoken');


module.exports = function(app, con, bcrypt) {

    const error = '{{"msg": "Bad Request", "code": 400}}';

    function check_account_mail (res, mail, callback) {
        con.execute('SELECT * FROM users WHERE email = ?', [mail], function(err, results, fields) {
            if (results.length > 0) {
                callback(84);
            } else {
                callback(0);
            }
        })
    }

    function register (res, mail, pwd, mname, fname) {
        con.execute('INSERT INTO users (email, password, last_name, first_name) VALUES (?, ?, ?, ?)', [mail, pwd, mname, fname], function(err, results, fields) {
            const token = jwt.sign({email:mail, password:pwd}, 'SECRET');
            res.status(200).json({token});
        })
    }

    /* Creating a new user. */
    app.post('/api/signin', (req, res) => {
        var name = req.body["last_name"];
        var fname = req.body["first_name"];
        var mail = req.body["email"];
        var pswd = req.body["password"];

        console.log("name = " + name + ", fname = " + fname + ", mail = " + mail + ", pswd = " + pswd);
        if (mail === undefined ||
            name === undefined  ||
            fname === undefined ||
            pswd === undefined) {
            res.status(500).json({"msg":"Internal server error"});
            return;
        }
        pswd = bcrypt.hashSync(pswd, 10);
        check_account_mail(res, mail, function(nbr) {
            if (nbr == 84) {
                res.status(409).json({"msg":"Error 409, conflict"});
                return;
            } else {
                register(res, mail, pswd, name, fname);
                return;
            }
        });
    });

    /* A post request to the login page. It is checking if the email and password
    are undefined. If they are, it throws an error. If they are not, it queries
    the database to see if the email and password match. If they do, it returns
    the result. If they don't, it throws an error. */
    app.post('/api/login', (req, res) => {
        console.log("Login attempt as")
        var sql = "SELECT * FROM users WHERE email = '" + req.body.email + "'";
        con.query( sql, function(err, results, fields) {
            console.log(sql);
            console.log(results);
            if (results[0] == undefined || results[0].password === undefined) {
                res.status(400).json({"msg": 'Invalid Credentials',});
            } else {
                bcrypt.compare(req.body.password, results[0].password, function(err, result) {
                    if (result == true) {
                        var token = jwt.sign({ id: results[0].id }, "SECRET", {
                            expiresIn: 86400
                        });
                        console.log("token is " + token);
                        res.status(200).json({ "token": token, "id" : results[0].id });
                    } else {
                        res.status(400).json({"msg": 'Invalid Credentials',});
                    }
                });
            }
        }
    );
    });

    /* Getting the user with the id of the url. */
    app.get('/api/user/:id', (req, res)=>{
        const id = parseInt(req.params.id)
        con.query("SELECT * FROM users WHERE id = " + id.toString(), function (err, result, fields) {
            if (err)
                res.status(400).json({"msg": err});
            res.status(200).json(result[0])
        })
    })

    /* Getting the topic with the url of the url. */
    app.get('/api/topic/:url', (req, res)=>{
        const url = encodeURIComponent(req.params.url)
        console.log('SELECT * FROM topics INNER JOIN comments ON topics.id = comments.topic_id INNER JOIN users ON users.id = comments.user_id WHERE comments.url = "' + url + '" ORDER BY comments.id DESC')
        con.query('SELECT * FROM topics INNER JOIN comments ON topics.id = comments.topic_id INNER JOIN users ON users.id = comments.user_id WHERE comments.url = "' + url + '" ORDER BY comments.id DESC', function (err, result, fields) {
            if (err) {
                console.log("Error : " + err);
                res.status(400).json({"msg": err});
            } else {
                res.status(200).json(result)
            }
        })
    })

    app.get('/api/topicid/:url', (req, res)=>{
        const url = encodeURIComponent(req.params.url)
        con.query('SELECT id FROM topics WHERE url = "' + url + '"', function (err, result, fields) {
            if (err)
                res.status(400).json({"msg": err});
            res.status(200).json(result)
        })
    })

    /* Creating a new topic. */
    app.post('/api/topic', (req,res) => {
        if (req.body.url === undefined) {
            res.status(400).json({"msg": "Missing fields"});
            return
        }
        con.query("INSERT INTO topics (url) VALUES (" + '"' + encodeURIComponent(req.body.url) + '")', function (err, result, fields) {})
    })

    app.post('/api/istopic', (req,res) => {
        if (req.body.url === undefined) {
            res.status(400).json({"msg": "Missing fields"});
        }
        con.query("SELECT * FROM topics WHERE url = '" + encodeURIComponent(req.body.url) + "'", function (err, result, fields) {
            if (err) {
                res.status(400).json({"msg": err});
                return
            } else if (result.length > 0) {
                res.status(409).json({"msg": "Topic already exists"});
            } else {
                res.status(200).json(result)
            }
        })
    })

    /* Creating a new comment. */
    app.post('/api/comment',  (req,res) => {
        console.log("new comment : ")
        if (req.body.user_id === undefined || req.body.content === undefined || req.body.topic_id === undefined || req.body.url === undefined)
            res.status(400).json({"msg": "Missing fields"});
        console.log("INSERT INTO comments (user_id, content, topic_id, url) VALUES (" +req.body.user_id + ', "' + req.body.content + '", ' + req.body.topic_id + ', "' + encodeURIComponent(req.body.url) + '")')
        con.query("INSERT INTO comments (user_id, content, topic_id, url) VALUES (" +req.body.user_id + ', "' + req.body.content + '", ' + req.body.topic_id + ', "' + encodeURIComponent(req.body.url) + '")', function (err, result, fields) {
            if (err)
                res.status(400).json({"msg": err});
            res.status(200).json(result)
        })
    })

    /* Getting the comment with the user_id of the url. */
    app.get('/api/comments/:id', (req,res) => {
        const id = parseInt(req.params.id)
        con.query("SELECT * FROM comments WHERE user_id = " + id + " ORDER BY value DESC", function (err, result, fields) {
            if (err)
                res.status(400).json({"msg": err});
            res.status(200).json(result)
        })
    })

    /* Updating the value of a comment by adding 1. */
    app.post('/api/like', auth, (req,res) => {
        if (req.body.comment_id === undefined)
            res.status(400).json({"msg": "Missing fields"});
        con.query("UPDATE comments SET value = value + 1 WHERE id = " + req.body.comment_id, function (err, result, fields) {
            if (err)
                res.status(400).json({"msg": err});
            res.status(200).json(result)
        })
    })

    /* Updating the value of a comment by sub 1. */
    app.post('/api/unlike', auth, (req,res) => {
        if (req.body.comment_id === undefined)
            res.status(400).json({"msg": "Missing fields"});
        con.query("UPDATE comments SET value = value - 1 WHERE id = " + req.body.comment_id, function (err, result, fields) {
            if (err)
                res.status(400).json({"msg": err});
            res.status(200).json(result)
        })
    })
}