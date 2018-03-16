/*
    Trying to solve the problem at here: http://www.spoj.com/problems/PRIME1/
*/
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

void eratosthenes(unsigned int start, unsigned int end) {
    bool *primes = new bool[end];

    unsigned int i = 3;
    while(i * i <= end) {
        for(unsigned int j = i * i; j <= end; j += i * 2) {
            primes[j] = true;
        }
        // get the next start point of the loop
        unsigned int next = i + 2;
        while(primes[next] != false && next <= end) {
            next += 2;
        }
        i = next;
    }
    if(2 >= start)
        cout << 2 << endl;
    if(start == 1 || start == 2)
        start = 3;
    else if(start % 2 == 0)
        start += 1;
    for(int i = start; i <= end; i += 2) {
        if(!primes[i])
            cout << i << endl;
    }
}

int main() {
    int n;
    cin >> n;
    unsigned int start, end;
    for(int i = 0; i < n; ++i) {
        cin >> start;
        cin >> end;
        clock_t begin = clock();
        eratosthenes(start, end);
        clock_t stop = clock();
        cout << "Elapsed time: " << (stop - begin) / CLOCKS_PER_SEC << endl;
        if(i != n - 1)
            cout << endl;
    }
    return 0;
}

