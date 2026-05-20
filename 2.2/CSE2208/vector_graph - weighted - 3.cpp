#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;

struct comparator{
    bool operator()(const edge &x, const edge &y){
        return x.second > y.second;
    }

};

int main()
{
    int N=6,adjN,label,t,w;
//    cout<<"Enter total number of Edges: ";
//    cin>>N;

    //vector<edge> graph;
    priority_queue<edge, vector<edge>, greater<edge>> graph;

    for(int i = 0; i < N; i++)
    {
        char u, v;
        int w;
        cin>>u>>v>>w;

        int src = u - 'A', dest = v - 'A';
        graph.push({w, {src, dest}});
    }

    cout<<endl;
    while(!graph.empty())
    {
        edge minm = graph.top();
        printf("%c -> %c : %d\n", minm.second.first + 'A', minm.second.second + 'A', minm.first);
        graph.pop();
    }


//    vector<int>graph[N];
//    for(int i=0;i<N;i++)
//    {
//        cout<<endl<<"Enter Node label/No.: ";
//        cin>>label;
//        cout<<endl<<"Enter total number of adjacent Nodes of Node "<<label<<" :";
//        cin>>adjN;
//        cout<<endl<<"Enter Adjacent nodes and weights of node "<<label<<" :";
//        for(int j=0;j<adjN;j++)
//        {
//            cin>>t>>w;
//            graph[label].push_back(t);
//        }
//
//    }
//    cout<<endl<<"Adjacency List:";
//    for(int i=0;i<N;i++)
//    {
//        if(graph[i].size()>0)
//        {
//            cout<<endl<<i<<"--> ";
//            for(int j=0;j<graph[i].size();j++)
//            {
//                cout<<graph[i][j]<<" ";
//            }
//        }
//
//    }



}
//graph
/*
    0---1
    |  /|\
    | / | \4
    |/  | /
    2---3/

    Total Nodes: 5

    ADJACENCY LIST :
    0-> 1,2
    1-> 0,2,3,4
    2-> 0,1,3
    3-> 1,2,4
    4-> 1,3


6
E A 7
A D 60
A C 12
C D 32
C B 20
B A 10

*/
