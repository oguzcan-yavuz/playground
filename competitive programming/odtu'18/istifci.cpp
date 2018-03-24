#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int volume_calculator(int a, int b, int c) {
    return a * b * c;
}

int main() {
    // hacim formulu: a * b * c
    int n, a, b, c;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    int room_volume = volume_calculator(a, b, c);
    int boxes[n][3];
    // get the inputs
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j)
            cin >> boxes[i][j];
    }

    // calculate volume of each box
    int volumes[n];
    for(int i = 0; i < n; ++i) {
        int a = boxes[i][0], b = boxes[i][1], c = boxes[i][2];
        volumes[i] = volume_calculator(a, b, c);
    }

    // find two boxes with maximum volume to fit into the room
    int max_volumes = 0;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int two_volumes = volumes[i] + volumes[j];
            if(two_volumes > max_volumes && two_volumes <= room_volume)
                max_volumes = two_volumes;
        }
    }

    // output
    cout << max_volumes << endl;
    return 0;
}
