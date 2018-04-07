/*
Find the smallest common multiple of the provided parameters that can be evenly divided by both, as well as by all sequential numbers in the range between these parameters.
The range will be an array of two numbers that will not necessarily be in numerical order.
e.g. for 1 and 3 - find the smallest common multiple of both 1 and 3 that is evenly divisible by all numbers between 1 and 3.
*/


function smallestCommons(arr) {
  // rearrange the array with min and max value
  var min = Math.min.apply(null, arr);
  var max = Math.max.apply(null, arr);
  // new array with numbers in range
  var new_arr = [];
  // loop through all numbers in range and push it to new array
  for (max; max >= min; max--) {
    new_arr.push(max);
  }
  // Note: I couldn't solve this from here and I copied this solution.
  // Variables needed declared outside the loops.
  var quot = 0;
  var loop = 1;
  var n;

  // run code while n is not the same as the array lenght.
  do {
    quot = new_arr[0] * loop * new_arr[1];
    for (n = 2; n < new_arr.length; n++) {
      if (quot % new_arr[n] !== 0) {
        break;
      }
    }
    loop++;
  } while (n !== new_arr.length); {
    return quot;
  }
}

smallestCommons([1, 5]);

