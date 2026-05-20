#include<bits/stdc++.h>
using namespace std;
typedef pair<char,char> pcc;
vector<pair<pcc,int> > node_vec;
int main(){
    int node_no,edge_no;
    cin>>node_no>>edge_no;
    for(int i=1;i<=edge_no;i++){
        char u,v;
        int w;
        cin>>u>>v>>w;
        node_vec.push_back(make_pair(make_pair(u,v),w));
    }
    for(int i=1;i<=edge_no;i++){
        cout<<i<<"->";
        cout<<node_vec[i].first.first<<","<<node_vec[i].first.second<<","<<node_vec[i].second;
        
        cout<<endl;
    }
    
    return 0;
}