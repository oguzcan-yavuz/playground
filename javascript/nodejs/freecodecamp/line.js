var fs = require('fs');
var f = fs.readFileSync(process.argv[2], 'utf-8');
var result = f.split('\n');
console.log(result.length - 1);
