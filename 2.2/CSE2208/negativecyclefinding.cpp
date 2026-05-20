#include<bits/stdc++.h>
using namespace std;

void initializeSource(int dist[], int predecessors[], int ver, int source)
{
    for(int i = 1; i <= ver; i++)
    {
        dist[i] = INT_MAX;
        predecessors[i] = -1;
    }
    dist[source] = 0;
}

bool relaxEdge(int dist[], int predecessors[], int from, int to, int weight)
{
    if(dist[to] > dist[from] + weight)
    {
        dist[to] = dist[from] + weight;
        predecessors[to] = from;
        return true;
    }
    return false;
}

void printShortestPath(int predecessors[], int source, int destination)
{
    stack<int> path;
    int temp = destination;
    while(predecessors[temp] != -1)
    {
        path.push(temp);
        temp = predecessors[temp];
    }

    cout << source;
    while(!path.empty())
    {
        int x = path.top();
        path.pop();
        cout << "->" << x ;
    }
}

void bellmanFord(vector<pair<int, int>> graph[], int source, int numVertices)
{
    int predecessors[numVertices + 1];
    int distances[numVertices + 1];
    int updateCount[numVertices + 1] = {0};
    int u, v, weight;

    initializeSource(distances, predecessors, numVertices, source);

    for(int i = 1; i <= numVertices - 1; i++)
    {
        for(int j = 1; j <= numVertices; j++)
        {
            for(int k = 0; k < graph[j].size(); k++)
            {
                u = j;
                v = graph[j][k].first;
                weight = graph[j][k].second;

                if(relaxEdge(distances, predecessors, u, v, weight))
                {
                    updateCount[v] += 1;
                }
            }
        }
        cout << "Iteration: " << i;
        for(int l = 1; l <= numVertices; l++)
        {
            cout << "Cost: " << distances[l] << "\t";
        }
        cout << endl;
    }

    bool negativeCycle = false;
    for(int j = 1; j <= numVertices; j++)
    {
        for(int k = 0; k < graph[j].size(); k++)
        {
            u = j;
            v = graph[j][k].first;
            weight = graph[j][k].second;

            if(relaxEdge(distances, predecessors, u, v, weight))
            {
                negativeCycle = true;
                break;
            }
        }
        if(negativeCycle) break;
    }

    if(negativeCycle) {
        cout << "The graph contains a negative cycle." << endl;
    }
    else {
        cout << "The graph does not contain a negative cycle." << endl;
        cout << endl;
        cout << "Number of updates done to nodes: ";

        for(int i = 1; i <= numVertices; i++)
        {
            cout << updateCount[i] << "\t";
        }

        cout << endl;
        cout << "Shortest paths";
        for(int i = 1; i <= numVertices; i++)
        {
            cout << i << ".\t";
            printShortestPath(predecessors, source, i);

            cout << "\tCost= " << distances[i];

            cout << endl;
        }
    }
}

int main()
{
    int numVertices, numEdges, source;

    cout << "Enter Node Number: ";
    cin >> numVertices;
    cout << "Enter Edge Number: ";
    cin >> numEdges;

    vector<pair<int, int>> adjacencyList[numVertices + 1];

    for(int i = 0; i < numEdges; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        adjacencyList[start].push_back(make_pair(end, weight));
    }

    cout << "Enter starting node: ";
    cin >> source;

    bellmanFord(adjacencyList, source, numVertices);
}
