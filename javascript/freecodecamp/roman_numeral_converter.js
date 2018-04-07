/*
Convert the given number into a roman numeral.
All roman numerals answers should be provided in upper-case.
*/


function convertToRoman(num) {
  // roman numerals
  var roman = [
    ["I", 1],
    ["V", 5], 
    ["X", 10], 
    ["L", 50], 
    ["C", 100], 
    ["D", 500], 
    ["M", 1000]
  ];
  
  // converting int to an array
  var digits = ("" + num).split("").reverse();
  
  var results = [];
  // starts from number's ones step and keeps looping, increasing values every step
  for (var f = 0; f < digits.length; f++) {
    if (digits[f] <= 3) {
      // pushes first 3 elements of a roman number to results array
      results.push(roman[f * 2][0].repeat(digits[f]));
      } else if (digits[f] <= 5) {
        if (digits[f] == 4) {
          // pushes fourth element of a roman number to results array
          results.push(roman[f * 2][0].concat(roman[(f * 2) + 1][0]));
        } else
          // pushes fifth element of a roman number to results array
          results.push(roman[(f * 2) + 1][0]);
      } else if (digits[f] <= 8) {
        // pushes 6th, 7th, 8th elements
        results.push(roman[(f * 2) + 1][0].concat(roman[f * 2][0].repeat(digits[f] - 5)));
      } else {
        // pushes 9th element
        results.push(roman[f * 2][0].concat(roman[(f * 2) + 2][0]));
      }
  }
  return results.reverse().join("");
}

convertToRoman(3999);

