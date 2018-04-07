/*
Create a function that sums two arguments together. If only one argument is provided, then return a function that expects one argument and returns the sum.
For example, addTogether(2, 3) should return 5, and addTogether(2) should return a function.
Calling this returned function with a single argument will then return the sum:
var sumTwoAnd = addTogether(2);
sumTwoAnd(3) returns 5.
If either argument isn't a valid number, return undefined.
*/


function addTogether() {
  
  // create a function to check if the arguments are number or not
  var check = function (number) {
    if (typeof number !== 'number') {
      return undefined;
    } else {
      return number;
    }
  };
  
  // if we have two arguments, check them and return sum of them
  if (arguments.length > 1) {
    var a = check(arguments[0]);
    var b = check(arguments[1]);
    
    // checking arguments
    if (a === undefined || b === undefined) {
      return undefined;
    } else {
      return a + b;
    }
  // if we have one argument, return a function that takes the argument in second parenthesis
  } else {
    var c = arguments[0];
    // check first argument
    if (check(c)) {
      // this is where we create the function
      return function(secondArg) {
        // check second argument
        if (check(secondArg) === undefined) {
          return undefined;
        } else {
          return c + secondArg;
        }
      };
    }
  }
  
}

addTogether(5)([2]);

