function lol(asd) {
    var stream = require('stream');
    var echoStream = new stream.Writable();
    var result = "";
    echoStream._write = function (chunk, encoding, done) {
        result += (chunk.toString());
        done();
    };
    echoStream.end = function() {
        asd(result.length + '\n' + result);
    };
return echoStream;
}

var http = require('http');
var url = process.argv[2];
http.get(url, function(res){
    res.setEncoding("utf-8");
    res.pipe(lol(console.log));
});

/* OFFICIAL SOLUTION

var http = require('http')
    var bl = require('bl')
    
    http.get(process.argv[2], function (response) {
      response.pipe(bl(function (err, data) {
        if (err) {
          return console.error(err)
        }
        data = data.toString()
        console.log(data.length)
        console.log(data)
      }))
    })
*/