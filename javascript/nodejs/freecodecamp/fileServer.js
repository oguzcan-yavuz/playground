var http = require('http');
var fs = require('fs');

var server = http.createServer((req, res) => {
    var text = fs.createReadStream(process.argv[3]);
    text.pipe(res);
});
server.listen(process.argv[2]);
