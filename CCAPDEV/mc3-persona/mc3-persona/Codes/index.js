const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost:27017/MC3_Votes_persona');

const express = require('express');
const app = new express();

const Vote = require("./models/Vote");
const path = require('path'); 

app.use(express.json());
app.use(express.urlencoded( {extended: true})); 
app.use(express.static('public'));

var hbs = require('hbs');
app.set('view engine','hbs');

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Edit at this point onwards
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

app.get('/', function (req, res) {
    // TODO: Render index.html (10 pts.)
    // HINT: "All-in-one Backend kit's index.js line 26"
    res.sendFile(__dirname + '\\' + 'index.html');
});

app.get('/vote', function (req, res) {
    // TODO: Create an instance of a Vote document. Use the .create() method from the declared Vote object
    // HINT: You may refer to the "All-in-one Backend kit (Good for your mental health edition)"
    // index.js file lines 38, 39, and 41
    Vote.create({
        q: req.query.q
    })
    res.redirect('/confirm');
    // TODO: Redirect to the confirm route (10 pts.)
    // HINT: "All-in-one Backend kit's index.js line 43"
});

app.get('/confirm', function (req, res) {
    // TODO: Render confirm.html (10 pts.)
    // HINT: "All-in-one Backend kit's index.js line 26"
    res.sendFile(__dirname + '\\' + 'confirm.html');
});

app.get('/results', async (req, res) => {
    // TODO: Create a JSON object that contains the no. of votes for a particular member.
    // Ex: hanayo = no. of hanayo's votes, rin = no. of rin's votes, etc.
    // Variables are named for you so you don't have to memorize their names. :)

    // Step 1: Assign these variables with the correct values resulting from querying MongoDB using Mongoose
    // HINT: "All-in-one Backend kit's index.js line 49". Replace the {} with the correct query:
    //  ex {q:'blackpink'} = query returns ALL documents where q = 'blackpink'
    var ren = await Vote.find({q:'ren'});
    var ryuji = await Vote.find({q:'ryuji'});
    var ann = await Vote.find({q:'ann'});
    var makoto = await Vote.find({q:'makoto'});
    var yusuke = await Vote.find({q:'yusuke'});
    var futaba = await Vote.find({q:'futaba'});
    var haru = await Vote.find({q:'haru'});
    var morgana = await Vote.find({q:'morgana'});

    // TODO: Build the JSON object, and replace the values with the correct corresponding no. of votes
    // of that particular member.
    // HINT: length() can be used to determine the number of entries in a collection of documents obtained from a query
    var results = {};
    results = {'ren':Object.keys(ren).length,
    'ryuji':Object.keys(ryuji).length,
    'ann':Object.keys(ann).length,
    'makoto':Object.keys(makoto).length,
    'yusuke':Object.keys(yusuke).length,
    'futaba':Object.keys(futaba).length,
    'haru':Object.keys(haru).length,
    'morgana':Object.keys(morgana).length};

     // TODO: Pass the values to be rendered into the handlebar. 
     // HINT: "All-in-one Backend kit's index.js line 51". Replace the {} with the correct JSON object:
    res.render('results',{results});
});

var server = app.listen(3000, function () {
    console.log("CCAPDEV Mini Challenge #3: Persona 5, Dancing in Starlight!");
    console.log("Who is the best dancer at port 3000?");
    console.log(".");
});