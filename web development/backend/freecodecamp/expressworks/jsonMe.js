const express = require('express');
const fs = require('fs');
var app = express();

app.get('/books', (req, res) => {
    fs.readFile(process.argv[3], (err, data) => {
        if(err) return res.sendStatus(500);
        res.json(JSON.parse(data));
    });
});
app.listen(process.argv[2]);
