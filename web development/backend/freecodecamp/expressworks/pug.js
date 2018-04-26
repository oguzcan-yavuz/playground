const express = require('express');
var app = express();

app.set('view engine', 'pug');
app.set('views', process.argv[3]);
app.get('/home', (req, res) => {
    var date = new Date().toDateString();
    res.render('index', {date: date});
});
app.listen(process.argv[2]);
