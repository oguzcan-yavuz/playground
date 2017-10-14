primes.add(2);
primes.add(3);
int j = 2;
// handle 2's exponents and 3's exponents
for(int i = 4; i < number; i += 2) {
	// burada 3 ussunun son degerine gelince index hatasi verecek
	// donguyu daha once bitirmek lazim ama nerede?
	// ya da dongu icerisine bir kontrol eklemek?
	isPrime[i] = false;
	isPrime[i + j] = false;
	j++;
}

for(int i = 5; i <= Math.sqrt(n); i += 6) {
	if(n % i == 0 or n % (i + 2) == 0)
		isPrime[i] = false;
	else
		primes.add(i);
}

