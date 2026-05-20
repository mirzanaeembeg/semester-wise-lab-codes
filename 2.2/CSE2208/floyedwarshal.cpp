#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<vector<int>> floyd_warshall(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> distance(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                distance[i][j] = 0;
            } else if (graph[i][j] != 0) {
                distance[i][j] = graph[i][j];
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    return distance;
}

void print_matrix(vector<vector<int>>& distance) {
    cout << "Shortest distance between every pair of vertices..\n";
    for (int i = 0; i < distance.size(); i++) {
        for (int j = 0; j < distance[i].size(); j++) {
            if (distance[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << distance[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    vector<vector<int>> graph = { {0, 5, 8, 0}, {-3, 0, 2, 0}, {4, 2, 0, 1}, {9, 0, 7, 0} };

    vector<vector<int>> shortest_distances = floyd_warshall(graph);
    print_matrix(shortest_distances);

    return 0;
}
