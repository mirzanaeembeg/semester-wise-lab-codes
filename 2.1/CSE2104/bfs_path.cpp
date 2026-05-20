#include <bits/stdc++.h>
using namespace std;
vector<int> Node_Vec[11];
int level[11];
int parent[11];
void path(int dest)
{
    cout << dest << " ";
    if (parent[dest] != dest)
    {
        path(parent[dest]);
    }
}
void bfs(int source)
{
    for (int i = 0; i < 11; i++)
    {
        level[i] = INT_MAX;
        parent[i] = i;
    }
    queue<int> q;
    q.push(source);
    level[source] = 0;
    while (!(q.empty()))
    {
        int u = q.front();
        q.pop();
        for (int j = 0; j < Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if (level[v] == INT_MAX)
            {
                q.push(v);
                level[v] = level[u] + 1;
                parent[v] = u;
            }
        }
    }
}
int main()
{
    int node_no, edge_no;
    printf("Enter the number of nodes: ");
    scanf("%d", &node_no);
    printf("Enter the number of edges: ");
    scanf("%d", &edge_no);
    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        scanf("%d %d", &nodeA, &nodeB);
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }
    for (int i = 1; i <= node_no; i++)
    {
        printf("%d -> ", i);
        for (int j = 0; j < Node_Vec[i].size(); j++)
        {
            printf("%d ", Node_Vec[i][j]);
        }
        printf("\n");
    }
    bfs(10);
    for (int i = 0; i < 11; i++)
    {
        cout << i << "->" << parent[i] << endl;
    }
    cout<<"Path..\n";
    path(2);
    return 0;
}