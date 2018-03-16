#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // inputs
    string str;
    getline(cin, str);
    int n;
    cin >> n;
    int subs[n][2];
    for(int i = 0; i < n; ++i) {
        cin >> subs[i][0];
        cin >> subs[i][1];
    }
    // logic
    for(int i = 0; i < n; ++i) {
        string sub = str.substr(subs[i][0], subs[i][1]);


    }

    return 0;
}
