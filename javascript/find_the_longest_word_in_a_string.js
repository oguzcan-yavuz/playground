/*
Return the length of the longest word in the provided sentence.
Your response should be a number.
*/


function findLongestWord(str) {
  str.replace(/[^0-9a-z]/gi, '');
  
  var str_a = [ ];
  var largest = 0;
  
  str_a = str.split(' ');
  
  for (var i = 0; i < str_a.length; i++) {
    if (str_a[i].length > largest) {
      largest = str_a[i].length;
    }
  }
  return largest;
}

findLongestWord("What if we try a super-long word such as otorhinolaryngology");

