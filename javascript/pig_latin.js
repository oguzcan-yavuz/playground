/*
Translate the provided string to pig latin.
Pig Latin takes the first consonant (or consonant cluster) of an English word, moves it to the end of the word and suffixes an "ay".
If a word begins with a vowel you just add "way" to the end.
Input strings are guaranteed to be English words in all lowercase.
*/


function translatePigLatin(str) {
  var vowels = /[aeiou]/i;
  if (vowels.test(str[0])) {
    return str + "way";
  } else {
    var n = str.search(vowels);
    return str.slice(n) + str.slice(0, n) + "ay";
  }
}

translatePigLatin("glove");
