/*
Create a function that takes two or more arrays and returns an array of the symmetric difference (△ or ⊕) of the provided arrays.
Given two sets (for example set A = {1, 2, 3} and set B = {2, 3, 4}), the mathematical term "symmetric difference" of two sets is the set of elements which are in either of the two sets, but not in both (A △ B = C = {1, 4}). For every additional symmetric difference you take (say on a set D = {2, 3}), you should get the set with elements which are in either of the two the sets but not both (C △ D = {1, 4} △ {2, 3} = {1, 2, 3, 4}).
*/


  var candidates = [];
  // convert arguments dictionary to array.
  for(var key in arguments) {
    candidates.push(arguments[key]);
  }
  
  return Array.from(new Set(candidates.reduce(function(x, y) {
    var x_copy = x.filter(function(x_element) {
       return !(y.includes(x_element));
    });
    var y_copy = y.filter(function(y_element) {
      return !(x.includes(y_element));
    });
    return x_copy.concat(y_copy);
  })));
}

sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5]);

/* 
  better solution by Yengas:

function arrayIncludeChecker(arr){ return x => !arr.includes(x); }
function sym(args) {
  var candidates = [];
  // convert arguments dictionary to array.
  for(var key in arguments) {
    candidates.push(arguments[key]);
  }
  
  return Array.from(new Set(candidates.reduce(function(x, y) {
    var x_copy = x.filter(arrayIncludeChecker(y));
    var y_copy = y.filter(arrayIncludeChecker(x));
    return x_copy.concat(y_copy);
  })));
}

sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5]);

  even better solution by Yengas again:
  
function arrayIncludeChecker(arr){ return x => !arr.includes(x); }
function sym(args) {
  var candidates = [];
  // convert arguments dictionary to array.
  for(var key in arguments) {
    candidates.push(arguments[key]);
  }
  
  return Array.from(new Set(candidates.reduce((x, y) =>
    [...x.filter(arrayIncludeChecker(y)), ...y.filter(arrayIncludeChecker(x))]
  )));
}

sym([1, 1, 2, 5], [2, 2, 3, 5], [3, 4, 5, 5]);
*/


