const express = require('express');
const bodyParser = require('body-parser');

var app = express();
var router = express.Router();

app.use(bodyParser.urlencoded({ extended: false }));

function strReverser(str) {
    return str.split("").reverse().join("");
}

// a good practice of using routers is separating router processes to another files
// and then exporting them in our main app
router.post('/form', (req, res) => {
    res.send(strReverser(req.body.str));
});

app.use('/', router);
app.listen(process.argv[2]);

