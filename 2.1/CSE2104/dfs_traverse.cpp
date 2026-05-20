#include <bits/stdc++.h>
using namespace std;

vector<int> Node_Vec[11];
string color[11];

void dfs(int source, int dest)
{
    int u = source;
    color[u] = "gray";
    cout << u << " ";

    for (int j = 0; j < Node_Vec[u].size(); j++)
    {
        int v = Node_Vec[u][j];
        if (color[v] == "white")
        {
            dfs(v, dest);
        }
    }
    color[u] = "black";
}

int main()
{
    int node_no, edge_no;
    cout << "Enter the number of nodes: ";
    cin >> node_no;
    cout << "Enter the number of edges: ";
    cin >> edge_no;

    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }
    for (int i = 1; i <= node_no; i++)
    {
        color[i] = "white";
    }

    int source, dest;
    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the destination node: ";
    cin >> dest;

    cout << "DFS traversal: ";
    dfs(source, dest);

    return 0;
}
