var net = require('net');
var dateFormat = require('dateformat');
var server = net.createServer(function(c) {
    var now = new Date();
    now.setTime(now.getTime() - now.getTimezoneOffset() * 60 * 1000);
    var date = dateFormat(now, "GMT:yyyy-mm-dd HH:MM");
    c.write(date + "\n");
    c.end();
});
server.listen(process.argv[2]);
