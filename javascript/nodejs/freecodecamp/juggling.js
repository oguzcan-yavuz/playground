var bl = require('bl');
var http = require('http');

function juggle(links) {
    var link = links.shift();
    http.get(link, function(response) {
        response.pipe(bl(function(err, data) {
            if(err)
                return console.error(err);
            console.log(data.toString());
            if(links.length !== 0)
                juggle(links);
        }))
    });
}

function main() {
    var links = [process.argv[2], process.argv[3], process.argv[4]];
    juggle(links);
}

main();
