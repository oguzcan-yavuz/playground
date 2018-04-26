const express = require('express');
const crypto = require('crypto');
var app = express();

app.put('/message/:id', (req, res) => {
    var sha1 = crypto.createHash('sha1');
    var str = new Date().toDateString() + req.params.id;
    sha1.update(str);
    var hash = sha1.digest('hex');
    res.send(hash);
});

app.listen(process.argv[2]);
