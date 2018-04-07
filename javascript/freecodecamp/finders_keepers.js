/*
Create a function that looks through an array (first argument) and returns the first element in the array that passes a truth test (second argument).
*/


function findElement(arr, func) {
  var new_arr = [];
  new_arr.push(arr.filter(func));
  return new_arr[0][0];
}

findElement([1, 2, 3, 4], function(num){ return num % 2 === 0; });

