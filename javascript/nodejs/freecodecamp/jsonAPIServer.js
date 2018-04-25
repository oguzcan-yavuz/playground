var http = require('http');

function parseTime(givenDate) {
    var keys = ["hour", "minute", "second"];
    var values = [givenDate.getHours(), givenDate.getMinutes(), givenDate.getSeconds()];
    // zips keys and values to an object
    return keys.reduce((obj, k, i) => ({...obj, [k]: values[i]}), {});
}

function unixTime(givenDate) {
    return {"unixtime": givenDate.getTime()};
}

function convertQueryToDate(query) {
    var key = "iso=";
    var endOfISOKey = query.search(key) + key.length;
    query = query.split("");
    var fullDate = query.slice(endOfISOKey).join("");
    var milisecs = Date.parse(fullDate);
    return new Date(milisecs);
}

var server = http.createServer((req, res) => {
    var queryPattern = /^\/api\/(parse|unix)time\?iso=\d{4}(-\d{2}){2}T(\d{2}:){2}\d{2}\.\d{3}Z$/;
    var query = req.url;
    if(req.method === "GET" && queryPattern.test(query)) {
        var givenDate = convertQueryToDate(query);
        var isParseTime = query.search("parse");
        res.write(JSON.stringify((isParseTime !== -1) ? parseTime(givenDate) : unixTime(givenDate)));
    }
    res.end();
});
server.listen(process.argv[2]);


/* OFFICIAL SOLUTION
  var http = require('http')
    var url = require('url')

    function parsetime (time) {
      return {
        hour: time.getHours(),
        minute: time.getMinutes(),
        second: time.getSeconds()
      }
    }

    function unixtime (time) {
      return { unixtime: time.getTime() }
    }

    var server = http.createServer(function (req, res) {
      var parsedUrl = url.parse(req.url, true)
      var time = new Date(parsedUrl.query.iso)
      var result

      if (/^\/api\/parsetime/.test(req.url)) {
        result = parsetime(time)
      } else if (/^\/api\/unixtime/.test(req.url)) {
        result = unixtime(time)
      }

      if (result) {
        res.writeHead(200, { 'Content-Type': 'application/json' })
        res.end(JSON.stringify(result))
      } else {
        res.writeHead(404)
        res.end()
      }
    })
    server.listen(Number(process.argv[2]))

 */
