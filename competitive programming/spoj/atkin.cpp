/*
    Trying to solve the problem at here: http://www.spoj.com/problems/PRIME1/
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

void atkin(unsigned int start, unsigned int end) {
    bool *primes = new bool[end + 1];
    primes[2] = true;
    primes[3] = true;
    unsigned int boundary = ceil(sqrt(end));
    for(unsigned int x = 1; x <= boundary; ++x) {
        for(unsigned int y = 1; y <= boundary; ++y) {
            unsigned int n;
            // 3.1
            n = (4 * x * x) + (y * y);
            if(n <= end && (n % 12 == 1 || n % 12 == 5))
                primes[n] ^= true;
            // 3.2
            n = (3 * x * x) + (y * y);
            if(n <= end && (n % 12 == 7))
                primes[n] ^= true;
            // 3.3
            n = (3 * x * x) - (y * y);
            if(n <= end && (n % 12 == 11))
                primes[n] ^= true;
        }
    }
    // mark squares of primes as non prime
    for(unsigned int i = 5; i <= boundary; ++i) {
        if(primes[i]) {
            for(unsigned j = i * i; j <= end; j += j)
                primes[j] = false;
        }
    }
    // output
    if(start == 1 || start == 2) {
        cout << 2 << endl;
        start = 3;
    } else if(start % 2 == 0) {
        ++start;
    }
    for(unsigned int i = start; i <= end; i += 2) {
        if(primes[i])
            cout << i << endl;
    }

}

int main() {
    // int t1 = 999900000;
    // int t2 = 1000000000;
    int n;
    cin >> n;
    unsigned int start, end;
    for(int i = 0; i < n; ++i) {
        cin >> start;
        cin >> end;
        clock_t begin = clock();
        atkin(start, end);
        clock_t stop = clock();
        cout << "Elapsed time: " << (stop - begin) / CLOCKS_PER_SEC << endl;
        if(i != n - 1)
            cout << endl;
    }
    return 0;
}
