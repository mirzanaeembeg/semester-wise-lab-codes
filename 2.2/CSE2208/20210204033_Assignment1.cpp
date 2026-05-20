#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<int> level;
vector<vector<pii>> Node_Vec;

void bfs(int source) {
    queue<int> q;
    q.push(source);
    level[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int j = 0; j < Node_Vec[u].size(); j++) {
            int v = Node_Vec[u][j].first;
            int weight = Node_Vec[u][j].second;
            if (level[v] == INT_MAX) {
                q.push(v);
                level[v] = level[u] + weight;
            }
        }
    }
}

int main() {
    int numNodes, numEdges;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    level.resize(numNodes + 1, INT_MAX);
    Node_Vec.resize(numNodes + 1);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        Node_Vec[u].push_back(make_pair(v, w));
    }

    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    bfs(sourceNode);

    cout << "Shortest distances from node " << sourceNode << ":\n";
    for (int i = 1; i <= numNodes; ++i) {
        cout << "To node " << i << ": ";
        if (level[i] == INT_MAX) {
            cout << "Not reachable\n";
        } else {
            cout << level[i] << "\n";
        }
    }

    return 0;
}
