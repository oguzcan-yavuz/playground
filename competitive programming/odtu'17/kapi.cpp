#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    int doors[n];
    int brushes[k];
    // doors
    for(int i = 0; i < n; ++i)
        cin >> doors[i];
    // brushes
    for(int i = 0; i < k; ++i)
        cin >> brushes[i];
    // painting
    int beauty = 0;
    for(int i = 0; i < n; ++i) {
        int *max_brush = max_element(brushes, brushes + k);
        int *max_door = max_element(doors, doors + n);
        int brush_index = distance(brushes, max_brush);
        int door_index = distance(doors, max_door);
        cout << "max brush: " << *max_brush << endl;
        cout << "max door: " << *max_door << endl;
        cout << "brush index: " << brush_index << endl;
        cout << "door index: " << door_index << endl;
        beauty += *max_door * *max_brush;
        brushes[brush_index] -= 1;
        doors[door_index] = 0;
    }
    // output
    cout << beauty << endl;
    return 0;
}