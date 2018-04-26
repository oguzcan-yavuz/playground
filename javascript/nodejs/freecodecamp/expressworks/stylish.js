const express = require('express');
const path = require('path');
const stylus = require('stylus');
var app = express();

app.use(stylus.middleware({
    src: process.argv[3],
    dst: process.argv[3]
    // compile: compileFunction     // this might be a good practice while using stylus
}));

app.use(express.static(process.argv[3] || path.join(__dirname, 'public')));

// this might be a good practice while using stylus
function compileFunction(str) {
    return stylus(str).set('compress', true);
}

app.get("/", (req, res) => {
    res.render('index');
});
app.listen(process.argv[2]);
