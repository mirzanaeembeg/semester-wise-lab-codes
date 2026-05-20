#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Node_Vec;
vector<string> color;

void dfs(int source)
{
    int u = source;
    color[u] = "gray";
    cout << u << " ";

    for (int j = 0; j < Node_Vec[u].size(); ++j)
    {
        int v = Node_Vec[u][j];
        if (color[v] == "white")
        {
            dfs(v);
        }
    }
    color[u] = "black";
}

int main() {
    int numNodes, numEdges;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    Node_Vec.resize(numNodes + 1);
    color.resize(numNodes + 1, "white");

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        Node_Vec[u].push_back(v);
    }

    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    cout << "DFS traversal: ";
    dfs(sourceNode);

    return 0;
}
