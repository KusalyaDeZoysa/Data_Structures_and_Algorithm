#include <iostream>
using namespace std;

const int INF = 1e9; // Large enough value to represent infinity

int findMinTime(int time[], bool visited[]) {
    int minimum = INF, index;

    for (int i = 0; i < 6; i++) {
        if (!visited[i] && time[i] <= minimum) {
            minimum = time[i];
            index = i;
        }
    }
    return index;
}

void DijkstraAlgorithm(int graph[6][6], int source) {
    int time[6];
    bool visited[6];

    for (int i = 0; i < 6; i++) {
        time[i] = INF;
        visited[i] = false;
    }

    time[source] = 0;

    for (int i = 0; i < 6; i++) {
        int minTime = findMinTime(time, visited);
        visited[minTime] = true;

        for (int j = 0; j < 6; j++) {
            if (!visited[j] && graph[minTime][j] && time[minTime] != INF &&
                time[minTime] + graph[minTime][j] < time[j]) {
                time[j] = time[minTime] + graph[minTime][j];
            }
        }
    }

    cout << "City\t\tTime from Source City" << endl;
    for (int i = 0; i < 6; i++) {
        cout << i << "\t\t\t" << time[i] << endl;
    }
}

int main() {
    int graph[6][6] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    DijkstraAlgorithm(graph, 0);

    return 0;
}

