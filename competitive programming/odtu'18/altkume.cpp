#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool is_divisible(unsigned long long int n) {
    if(n < 10)
        return false;
    for(int i = 1; i <= 10; ++i) {
        if(n % i != 0)
            return false;
    }
    return true;
}

int main() {
    // inputs
    unsigned long long int n;
    cin >> n;
    unsigned long long int numbers[n];
    for(unsigned long long int i = 0; i < n; ++i)
        cin >> numbers[i];

    // check the sum of subsets of numbers in numbers array is divisible
    unsigned long long int total_subsets = 0;
    unsigned long long int max_subsets = pow(2, n);
    for(unsigned long long int i = 1; i < max_subsets; ++i) {
        unsigned long long int current_sum = 0;
        // create binary representation of the decimal and use those bits as array indexes
        vector<unsigned long long int> index_vec;
        unsigned long long int j = i;
        while(j > 0) {
            index_vec.push_back(j % 2);
            j /= 2;
        }
        // get the subset from binary representation
        for(unsigned long long int i = 0; i < index_vec.size(); ++i) {
            if(index_vec[i] == 1) {
                current_sum += numbers[i];
            }
        }
        // check if the sum of subset values are divisible
        if(is_divisible(current_sum))
            ++total_subsets;
    }
    total_subsets %= (int) pow(10, 9) + 7;
    cout << total_subsets << endl;

    return 0;
}
