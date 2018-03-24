#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned long long int x, n, k;
    cin >> x;
    cin >> n;
    cin >> k;
    // calculate starting value
    unsigned long long int start = 0;
    for(unsigned long long int i = 0; i < n; ++i)
        start += x * pow(10, i);

    // calculate S = 0 -> k => C * 10 ^ i
    unsigned long long int total = 0;
    for(unsigned long long int i = 0; i < k; ++i)
        total += start * pow(10, i);

    cout << total << endl;

    return 0;
}
