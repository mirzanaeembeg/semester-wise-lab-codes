#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

pair<vector<vector<int>>, vector<vector<int>>> floyd_warshall(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> distance(n, vector<int>(n, INF));
    vector<vector<int>> predecessor(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                distance[i][j] = 0;
            } else if (graph[i][j] != 0) {
                distance[i][j] = graph[i][j];
                predecessor[i][j] = i;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF && distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    predecessor[i][j] = predecessor[k][j];
                }
            }
        }
    }

    return make_pair(distance, predecessor);
}

void print_distance_matrix(vector<vector<int>>& distance) {
    cout << "Shortest distance between every pair of vertices:\n";
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

void print_predecessor_matrix(vector<vector<int>>& predecessor) {
    cout << "Predecessor of every vertex on the shortest path:\n";
    for (int i = 0; i < predecessor.size(); i++) {
        for (int j = 0; j < predecessor[i].size(); j++) {
            if (predecessor[i][j] == -1)
                cout << "NIL" << " ";
            else
                cout << predecessor[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4; //0 indexing. predecessor less than 1 of calculated value
    vector<vector<int>> graph = { {0, 3, 4, 0}, {0, 0, 0, 2}, {0, 5, 0, 0}, {1, 0, -4, 0} };

    pair<vector<vector<int>>, vector<vector<int>>> result = floyd_warshall(graph);
    vector<vector<int>> shortest_distances = result.first;
    vector<vector<int>> predecessors = result.second;
    print_distance_matrix(shortest_distances);
    print_predecessor_matrix(predecessors);

    return 0;
}
