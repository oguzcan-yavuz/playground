#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int unhappiness = 0;
    int *r = new int[n];
    int *g = new int[n];
    int *b = new int[n];
    int *arrs[3] = {r, g, b};
    int avgs[3] = {0, 0, 0};
    // get the inputs
    for(int i = 0; i < n; ++i) {
        cin >> r[i];
        cin >> g[i];
        cin >> b[i];
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < n; ++j) {
            avgs[i] += arrs[i][j];
        }
        avgs[i] /= n;
        for(int k = 0; k < n; ++k) {
            unhappiness += abs(avgs[i] - arrs[i][k]);
        }
    }
    cout << unhappiness << endl;
    return 0;
}
