/*
Drop the elements of an array (first argument), starting from the front, until the predicate (second argument) returns true.
The second argument, func, is a function you'll use to test the first elements of the array to decide if you should drop it or not.
Return the rest of the array, otherwise return an empty array.
*/


function dropElements(arr, func) {
  // Drop them elements.
  // If an element meet the requirement of the function
  // get that element's index and delete elements before that element
  for (var i = 0; i < arr.length; i++) {
    if (func(arr[i]) === true) {
      arr.splice(0, i);
      // return rest of the array
      return arr;
    }
  }
  
  // If none of the elements is not meet the requirement of the function
  // return an empty array
  if (func(arr) !== true) {
    return [];
  }
}

dropElements([1, 2, 3, 4], function(n) {return n > 5;});

