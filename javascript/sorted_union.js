/*
Write a function that takes two or more arrays and returns a new array of unique values in the order of the original provided arrays.
In other words, all values present from all arrays should be included in their original order, but with no duplicates in the final array.
The unique numbers should be sorted by their original order, but the final array should not be sorted in numerical order.
Check the assertion tests for examples.
*/


function uniteUnique(...arr) {
  var new_arr = [];
  var results = [];
  // gets all array elements and makes them elements of one array
  for (var i = 0; i < arr.length; i++) {
    for (var j = 0; j < arr[i].length; j++) {
      new_arr.push(arr[i][j]);
    }
  }
  // checks results array for every new_arr element
  for (var k = 0; k < new_arr.length; k++) {
    // if results array doesn't have that element, pushes it
    if (results.indexOf(new_arr[k]) === -1) {
      results.push(new_arr[k]);
    }
  }
  return results;
}

uniteUnique([1, 3, 2], [1, [5]], [2, [4]]);

