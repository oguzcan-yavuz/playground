var fs = require('fs');
var path = require('path');
var search = process.argv[2];
var extension = "." + process.argv[3];
fs.readdir(search, function(err, data) {
   if (err) console.error(err);
   data.forEach(function(file) {
       if(path.extname(file) == extension) {
           console.log(file);
       }
   });
});
