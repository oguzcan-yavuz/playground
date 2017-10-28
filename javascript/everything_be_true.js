/*
Check if the predicate (second argument) is truthy on all elements of a collection (first argument).
Remember, you can access object properties through either dot notation or [] notation.
*/


function truthCheck(collection, pre) {
  // Is everyone being true?
  
  // checks for if an element has the requested property and 
  //if the property is a valid value or not
  function check(element) {
    if (element[pre] && element.hasOwnProperty(pre)) {
      return true;
    } else {
      return false;
    }
  }
  
  // uses checks function for every element in the array
  if (collection.every(check)) {
    return true;
  } else {
    return false;
  }
}

truthCheck([{"single": "yes"}], "single");

