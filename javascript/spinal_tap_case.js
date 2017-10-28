/*
Convert a string to spinal case. Spinal case is all-lowercase-words-joined-by-dashes.
*/


function spinalCase(str) {
  var arr = str.split("");
  var upperCases = [];
  for (var i = 1; i < arr.length; i++) {
    // if no "space" between a lower case letter and an upper case letter
    if (arr[i] == arr[i].toUpperCase() && arr[i] !== " " && arr[i] !== "_" && arr[i] !== "-" && arr[i - 1] !== "-") {
      // get the index of that letter
      upperCases.push(i);
      // if the element is "space"
    } else if (arr[i] === " " || arr[i] === "_") {
      // change it with "-"
      arr[i] = "-";
    }
  }
  // for each indexs
  for (var j = 0; j < upperCases.length; j++) {
    // add "-" before that index
    arr[upperCases[j]] = "-" + arr[upperCases[j]];
  }
  arr = arr.join("");
  // make them all lower case
  arr = arr.toLowerCase();
  return arr;
}

spinalCase("AllThe-small Things");
