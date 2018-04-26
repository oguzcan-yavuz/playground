/*
Flatten a nested array. You must account for varying levels of nesting.
*/


function steamrollArray(arr) {
  // I'm a steamroller, baby
  var results = [];
  // Note: I couldn't solve this problem. I adapted a solution from Forum.
  // But solution is roger!
  function flat(args) {
    if (!Array.isArray(args)) {
      results.push(args);
    } else {
      for (var i = 0; i < args.length; i++) {
        flat(args[i]);
      }
    }
  }
  
  arr.forEach(flat);
  return results;
}

steamrollArray([1, [2], [3, [[4]]]]);
