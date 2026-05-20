#include<bits/stdc++.h>
using namespace std;
vector<int> node_vec[100];
//vector<int> node_cost[100];
int main(){
    int node_no,edge_no;
    cin>>node_no>>edge_no;
    for(int i=1;i<=edge_no;i++){
        int nodeA,nodeB,cost;
        cin>>nodeA>>nodeB;
        node_vec[nodeA].push_back(nodeB);
        node_vec[nodeB].push_back(nodeA);
        // node_cost[nodeA].push_back(cost);
    }
    cout<<"Adjacency List:\n";
    for(int i=1;i<=node_no;i++){
        cout<<i<<"->";
        for(int j=0;j<node_vec[i].size();j++){
            cout<<node_vec[i][j]<<",";
        }
        cout<<endl;
    }
    // for(int i=1;i<=node_no;i++){
    //     cout<<i<<"->";
    //     for(int j=0;j<node_vec[i].size();j++){
    //         cout<<node_cost[i][j]<<",";
    //     }
    //     cout<<endl;
    // }
    return 0;
}