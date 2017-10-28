/*
We'll pass you an array of two numbers. Return the sum of those two numbers and all numbers between them.
The lowest number will not always come first.
*/


function sumAll(arr) {
  
  var max = Math.max.apply(null, arr);
  var min = Math.min.apply(null, arr);
  var new_arr = Array.from(new Array(max - min + 1), (x,i) => i + min);
  var sum = new_arr.reduce(function(a, b) {
    return a + b;
  });
  return sum;
}

sumAll([10, 5]);

