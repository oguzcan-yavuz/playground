/*
    Trying to solve the problem at here: http://www.spoj.com/problems/PRIME1/
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void segmented_sieve(unsigned int start, unsigned int end) {
    unsigned int boundary = ceil(sqrt(end));
    bool *primes = new bool[boundary + 1];
    bool *is_prime = new bool[end - start + 1];
    // all primes to sqrt(end)
    unsigned int i = 3;
    while(i <= boundary) {
        if(!primes[i]) {
            for(unsigned int j = i * 2; j <= boundary; j += i) {
                primes[j] = true;
            }
        }
        i += 2;
    }

    // segmented
    unsigned int k = 2;
    while(k <= boundary) {
        if(!primes[k]) {
            for(int j = ((k - (start % k)) % k) + k; j < (end - start + 1); j += k) {
                is_prime[j] = true;
            }
        }
        if(k == 2)
            ++k;
        else
            k += 2;
    }
    // output
    if(start <= 2)
        cout << 2 << endl;
    unsigned int s = (start % 2 != 0) ? 0 : 1;
    for(s; s < (end - start + 1); s += 2) {
        if(s + start < 2)
            continue;
        if(!is_prime[s])
            cout << s + start << endl;
    }
}

int main() {
    int n;
    cin >> n;
    unsigned int inputs[n][2];
    for(int i = 0; i < n; ++i) {
        cin >> inputs[i][0];
        cin >> inputs[i][1];
    }
    for(int i = 0; i < n; ++i) {
        segmented_sieve(inputs[i][0], inputs[i][1]);
        if(i != n - 1)
            cout << endl;
    }
    return 0;
}
