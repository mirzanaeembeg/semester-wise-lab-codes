#include <bits/stdc++.h>
using namespace std;
vector<int> node_vec[6];
vector<int> node_cost[6];
int main()
{
    int node_no, edge_no;
    cout << "Enter node no:" << endl;
    cin >> node_no;
    cout << "Enter edge no:" << endl;
    cin >> edge_no;
    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;
        node_vec[nodeA].push_back(nodeB);
        node_cost[nodeA].push_back(cost);
    }
    for (int i = 1; i <= node_no; i++)
    {
        cout << i << "->";
        for (int j = 0; j < node_vec[i].size(); j++)
        {
            cout << node_vec[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= node_no; i++)
    {
        cout << i << "->";
        for (int j = 0; j < node_vec[i].size(); j++)
        {
            cout << node_cost[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
