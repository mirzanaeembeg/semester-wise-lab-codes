#include <bits/stdc++.h>
using namespace std;

#define V 5
int parent[V];

// Find set of vertex i
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

// Does union of i and j.
void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(vector<pair<int, pair<int, int>>> &edges)
{
	int mincost = 0; // Cost of min MST.

	// Initialize sets of disjoint sets.
	for (int i = 0; i < V; i++)
		parent[i] = i;

	// Include minimum weight edges one by one
	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (auto &edge : edges) {
			int i = edge.second.first;
			int j = edge.second.second;
			if (find(i) != find(j) && edge.first < min) {
				min = edge.first;
				a = i;
				b = j;
			}
		}

		union1(a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}

// driver program to test above function
int main()
{
	/* Let us create the following graph
		2 3
	(0)--(1)--(2)
	| / \ |
	6| 8/ \5 |7
	| /	 \ |
	(3)-------(4)
			9		 */
	vector<pair<int, pair<int, int>>> edges = {
		{2, {0, 1}}, {3, {1, 2}}, {6, {0, 3}},
		{8, {1, 3}}, {5, {1, 4}}, {7, {2, 4}},
		{9, {3, 4}}
	};

	// Print the solution
	kruskalMST(edges);

	return 0;
}
