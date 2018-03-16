#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    bool *arr = new bool[10];
    arr[0] = true;
    arr[3] = true;
    for(int i = 0; i < 10; i += 3) {
        arr[i] ^= true;
//        arr[i] = true;
    }
    for(int i = 0; i < 10; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
