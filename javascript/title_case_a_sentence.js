/*
Return the provided string with the first letter of each word capitalized. Make sure the rest of the word is in lower case.
For the purpose of this exercise, you should also capitalize connecting words like "the" and "of".
*/


function titleCase(str) {
  return str.replace(/\w\S*/g, function(str) { 
    return str.charAt(0).toUpperCase() + str.substr(1).toLowerCase();
  });
}

titleCase("I'm debugging eheEheEHEgEHEheHe");

