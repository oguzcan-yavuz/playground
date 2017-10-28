/*
Return an English translated sentence of the passed binary string.
The binary string will be space separated.
*/


function binaryAgent(str) {
  
  var res = [];
  
  function convert(val) {
    var powers = [128, 64, 32, 16, 8, 4, 2, 1];
    var sums = 0;
    for (var i = 0; i < val.length; i++) {
      if (val[i] == 1) {
        sums += powers[i];
      }
    }
    res.push(String.fromCharCode(sums));
  }
  
  str = str.split(" ");
  str.forEach(convert);
  return res.join("");
}

binaryAgent("01000001 01110010 01100101 01101110 00100111 01110100 00100000 01100010 01101111 01101110 01100110 01101001 01110010 01100101 01110011 00100000 01100110 01110101 01101110 00100001 00111111");

