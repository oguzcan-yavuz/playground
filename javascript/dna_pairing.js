/*
The DNA strand is missing the pairing element. Take each character, get its pair, and return the results as a 2d array.
Base pairs are a pair of AT and CG. Match the missing element to the provided character.
Return the provided character as the first element in each array.
For example, for the input GCG, return [["G", "C"], ["C","G"],["G", "C"]]
The character and its pair are paired up in an array, and all the arrays are grouped into one encapsulating array.
*/


function pairElement(str) {
  var basePairs = [["A", "T"], ["C", "G"], ["T", "A"], ["G", "C"]];
  var vals = str.split("");
  var results = [];
  for (var i in vals) {
    for (var k in basePairs) {
      if (basePairs[k][0] == vals[i]) {
        results.push(basePairs[k]);
      }
    }
  }
  return results;
}

pairElement("GCGA");

