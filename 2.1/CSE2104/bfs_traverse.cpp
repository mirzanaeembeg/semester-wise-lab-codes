#include <bits/stdc++.h>
using namespace std;
vector<int> Node_Vec[11];
int level[11];
void bfs(int source)
{
    for (int i = 0; i < 11; i++)
        level[i] = INT_MAX;
    queue<int> q;
    q.push(source);
    level[source] = 0;
    while (!(q.empty()))
    {
        int u = q.front();
        cout << q.front() << " ";
        q.pop();
        for (int j = 0; j < Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if (level[v] == INT_MAX)
            {
                q.push(v);
                level[v] = level[u] + 1;
            }
        }
    }
}
int main()
{
    int node_no, edge_no;
    printf("Enter the number of nodes: ");
    cin >> node_no;
    printf("Enter the number of edges: ");
    cin >> edge_no;
    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }
    cout << "Adjacency List:\n";
    for (int i = 1; i <= node_no; i++)
    {
        cout << i << "->";
        for (int j = 0; j < Node_Vec[i].size(); j++)
        {
            cout << Node_Vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << "BFS traverse:\n";
    bfs(1); // source 10
    cout << endl;
    cout << "Level or Shortest Path:\n";
    for (int i = 1; i < 11; i++)
    {
        cout << i << "->" << level[i] << endl;
    }
    return 0;
}