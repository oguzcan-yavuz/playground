var http = require('http');
var links = [process.argv[2], process.argv[3], process.argv[4]];
function juggling(i, n) {
    http.get(links[i], function(res){
        var result = "";
        res.setEncoding("utf-8");
        res.on("error", function(err){
            console.error(err);
        });
        res.on("data", function(data){
            result += data;
        });
        res.on("end", function(){
            console.log(result);
            if(i < n - 1) {
                i++;
                juggling(i, n);
            }
        });
    });
}
juggling(0, links.length);

/* OFFICIAL SOLUTION
var http = require('http')
    var bl = require('bl')
    var results = []
    var count = 0
    
    function printResults () {
      for (var i = 0; i < 3; i++) {
        console.log(results[i])
      }
    }
    
    function httpGet (index) {
      http.get(process.argv[2 + index], function (response) {
        response.pipe(bl(function (err, data) {
          if (err) {
            return console.error(err)
          }
    
          results[index] = data.toString()
          count++
    
          if (count === 3) {
            printResults()
          }
        }))
      })
    }
    
    for (var i = 0; i < 3; i++) {
      httpGet(i)
    }
*/
