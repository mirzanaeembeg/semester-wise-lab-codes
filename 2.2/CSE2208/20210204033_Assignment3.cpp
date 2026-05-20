#include <bits/stdc++.h>
using namespace std;

#define V 5
int parent[V];

int find_set(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void union_set(int i, int j)
{
	int a = find_set(i);
	int b = find_set(j);
	parent[a] = b;
}

void kruskalMST(vector<pair<int, pair<int, int>>> &edges)
{
	int mincost = 0;

	for (int i = 0; i < V; i++)
		parent[i] = i;

	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (auto &edge : edges) {
			int i = edge.second.first;
			int j = edge.second.second;
			if (find_set(i) != find_set(j) && edge.first < min) {
				min = edge.first;
				a = i;
				b = j;
			}
		}

		union_set(a, b);
		cout << "Edge " << edge_count++ << ":(" << a << ", " << b << ") cost:" << min << "\n";
		mincost += min;
	}
	printf("\nMinimum cost= %d\n", mincost);
}

int main()
{
	vector<pair<int, pair<int, int>>> edges = {
		{2, {0, 1}}, {3, {1, 2}}, {6, {0, 3}},
		{8, {1, 3}}, {5, {1, 4}}, {7, {2, 4}},
		{9, {3, 4}}
	};


	kruskalMST(edges);

	return 0;
}
