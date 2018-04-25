var fs = require('fs');
fs.readFile(process.argv[2], function(err, data) {
   if (err) return console.error(err);
   var str = data.toString().split('\n');
   console.log(str.length - 1);
});
