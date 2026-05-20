#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> node_vec;
vector<string> color;
stack<int> St;

void dfs(int source)
{
    int u = source;
    color[u] = "gray";

    for (int j = 0; j < node_vec[u].size(); ++j)
    {
        int v = node_vec[u][j];
        if (color[v] == "white")
        {
            dfs(v);
        }
    }
    St.push(u);
    color[u] = "black";
}

int main() {
    int numNodes, numEdges;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    node_vec.resize(numNodes + 1);
    color.resize(numNodes + 1, "white");

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        node_vec[u].push_back(v);
    }

    for(int i = 1; i < numNodes; ++i) {
        if(color[i] == "white") {
            dfs(i);
        }
    }

    cout << "Topological Sort: ";
    while(!St.empty()) {
        cout << St.top() << " ";
        St.pop();
    }

    return 0;
}
