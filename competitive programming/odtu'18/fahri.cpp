#include <iostream>

using namespace std;

int main() {
    // inputs
    unsigned int n;
    cin >> n;
    long int arr[n];
    for(unsigned int i = 0; i < n; ++i)
        cin >> arr[i];
    long int k;
    cin >> k;
    unsigned long int total_ranges = 0;
    // range boundaries
    for(unsigned int i = 0; i < n; ++i) {
        for(unsigned int j = i; j < n; ++j) {
            // looping through range, adding values together
            long int current_sum = 0;
            for(unsigned int k = i; k <= j; ++k) {
                current_sum += arr[k];
            }
            if(current_sum < k)
                ++total_ranges;
        }
    }
    // output
    cout << total_ranges << endl;
    return 0;
}
