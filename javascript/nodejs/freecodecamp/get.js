var http = require('http');
var url = process.argv[2];
http.get(url, function(res){
    var result = "";
    res.on("error", function(err){
        console.error(err);
    });
    res.setEncoding("utf-8");
    res.on("data", function(str) {
        result += str + "\n";
    });
    res.on("end", function(){
        console.log(result);
    });
});

/* OFFICIAL SOLUTION:

var http = require('http')
    http.get(process.argv[2], function (response) {
      response.setEncoding('utf8')
      response.on('data', console.log)
      response.on('error', console.error)
    }).on('error', console.error)
*/