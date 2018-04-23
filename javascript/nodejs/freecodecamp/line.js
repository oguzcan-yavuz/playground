var fs = require('fs');
fs.readFileSync(process.argv[2], 'utf-8');
var result = fs.split('\n');
console.log(result.length - 1);
