#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string test;
    int converted;
    getline(cin, test);
    stringstream(test) >> converted;
    cout << converted << endl;
    cout << "half of it: " << converted / 2 << endl;
    return 0;
}
