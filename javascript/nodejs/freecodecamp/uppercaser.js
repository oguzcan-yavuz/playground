var http = require('http');

var server = http.createServer((req, res) => {
    if(req.method === 'POST') {
        req.on('data', (chunk) => {
            res.write(chunk.toString().toUpperCase());
        });
        req.on('end', () => {
            res.end();
        })
    }
});
server.listen(process.argv[2]);
