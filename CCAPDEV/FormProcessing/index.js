var express = require('express');
var bodyParser = require('body-parser');

var app = express();
app.use(bodyParser.urlencoded({extended: false}));

app.get('/', function(req, res) {
    res.sendFile(__dirname+"\\"+'index.html');
});

app.get('/menu', function(req, res) {
    res.send("Viewing the restaurant menu!");
});

app.post('/submit-student-data', function(req,res) {
    var name = req.body.firstName + ' ' + req.body.lastName;
    res.send(name + " obtained");
});

var server = app.listen(5000, function() {
    console.log("Listening at port 5000...");
});