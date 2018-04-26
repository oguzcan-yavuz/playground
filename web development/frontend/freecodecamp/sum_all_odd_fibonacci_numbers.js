/*
Given a positive integer num, return the sum of all odd Fibonacci numbers that are less than or equal to num.
The first two numbers in the Fibonacci sequence are 1 and 1. Every additional number in the sequence is the sum of the two previous numbers. The first six numbers of the Fibonacci sequence are 1, 1, 2, 3, 5 and 8.
For example, sumFibs(10) should return 10 because all odd Fibonacci numbers less than 10 are 1, 1, 3, and 5.
*/


function sumFibs(num) {
  // first elements of a fibonacci number
  var a = 1;
  var b = 1;
  var odds = [1, 1];
  for (var i = 0; a < num; i++) {
    b = a + b;
    a += b;
    // if number is odd and le than num, push it to odds array
    if (a % 2 === 1 && a <= num) {
      odds.push(a);
    }
    if (b % 2 === 1 && b <= num) {
      odds.push(b);
    }
  }
  // sum all elements in odds array
  var sum = 0;
  for (var j = 0; j < odds.length; j++) {
    sum += odds[j];
  }
  return sum;
}

sumFibs(75025);

