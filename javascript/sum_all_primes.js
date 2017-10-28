/*
Sum all the prime numbers up to and including the provided number.
A prime number is defined as a number greater than one and having only two divisors, one and itself. For example, 2 is a prime number because it's only divisible by one and two.
The provided number may not be a prime.
*/


function sumPrimes(num) {
  
  // check function returns prime values
  function check(element, index, array) {
    return i % element !== 0;
  }
  
  // if number is less than 2, no prime numbers
  if (num < 2) {
    return "no prime numbers";
    // if number is ge than 2, loop every number
  } else {
    // 2 is prime as default, start from 3 to check numbers
  var primes = [2];
  var i = 3;    
  while (i <= num) {
    // if a number is not precisely divisible for all primes elements, add it to
    // primes array
    if (primes.every(check)) {
      primes.push(i);
    }
    i++;
  }
  
  // sum all elements in prime array
  var sums = 0;
  for (var k = 0; k < primes.length; k++) {
    sums += primes[k];
  }
    
  return sums;
  }
}

sumPrimes(15);

