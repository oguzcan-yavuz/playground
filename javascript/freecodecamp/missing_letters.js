/*
Find the missing letter in the passed letter range and return it.
If all letters are present in the range, return undefined.
*/


function fearNotLetter(str) {
  // checks for every letter in str string
  for (var i = 0; i < str.length - 1; i++) {
    // between letters, if there is more charCode gap more than 1
    if (str.charCodeAt(i + 1) - str.charCodeAt(i) > 1) {
      // returns the letter with +1 gap between last regular charCode
      return String.fromCharCode(str.charCodeAt(i) + 1);
    }
  }
}

fearNotLetter("abce");

