#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int graph[n + 1];

    for(int i = 0; i < n; ++i) {
        int index, value;
        cin >> index;
        cin >> graph[index];
    }

    int visited_cities = 0;
    int road_map[n];

    for(int i = 0; i < n; ++i) {
        int start = graph[i];
        int index = start;
        int current_visited = 1;
        int current_map[n] = { start };
        int map_index = 1;
        while(graph[index] != start) {
            current_map[map_index] = graph[index];
            ++map_index;
            ++current_visited;
            index = graph[index];
        }
        if(current_visited > visited_cities) {
            copy(current_map, current_map + (sizeof(current_map) / sizeof(current_map[0])), road_map);
            visited_cities = current_visited;
        }
    }
    // Output
    cout << visited_cities << endl;
    for(int i = 0 ; i < sizeof(road_map) / sizeof(road_map[0]); ++i) {
        if(road_map[i] != 0)
            cout << road_map[i] << " ";
    }
    cout << endl;
    return 0;
}
