#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> Node_Vec;
vector<string> color;
stack<int> Stack;
vector<int> dist;

void dfs(int source)
{
    int u = source;
    color[u] = "gray";

    for (auto &it : Node_Vec[u])
    {
        int v = it.first;
        if (color[v] == "white")
        {
            dfs(v);
        }
    }
    Stack.push(u);
    color[u] = "black";
}

void shortestPath(int source)
{
    dist[source] = 0;

    while (!Stack.empty())
    {
        int u = Stack.top();
        Stack.pop();

        if (dist[u] != INT_MAX)
        {
            for (auto &it : Node_Vec[u])
            {
                if (dist[it.first] > dist[u] + it.second)
                {
                    dist[it.first] = dist[u] + it.second;
                }
            }
        }
    }
}

int main() {
    int numNodes, numEdges;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    Node_Vec.resize(numNodes + 1);
    color.resize(numNodes + 1, "white");
    dist.resize(numNodes + 1, INT_MAX);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        Node_Vec[u].push_back({v, w});
    }

    for(int i = 1; i <= numNodes; ++i) {
        if(color[i] == "white") {
            dfs(i);
        }
    }

    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    shortestPath(sourceNode);

    cout << "Shortest distances from source node " << sourceNode << ":\n";
    for (int i = 1; i <= numNodes; ++i)
    {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}
