#include<iostream>
#include<vector>
using namespace std;

#define MAX 9999
int n = 4;
int distan[20][20] = {{0, 10, 15, 20},
                      {5, 0, 9, 10},
                      {6, 13, 0, 12},
                      {8, 8, 9, 0}
};
int completed_visit = (1<<n) -1;
int DP[32][8];
int parent[32][8];

int TSP(int mask, int pos) {
    if(mask == completed_visit) {
        return distan[pos][2];
    }
    if(DP[mask][pos] != -1) {
        return DP[mask][pos];
    }

    int ans = MAX;

    for(int city = 0; city < n; city++) {
        if((mask&(1<<city)) == 0) {
            int newAns = distan[pos][city] + TSP(mask|(1<<city), city);
            if(newAns < ans) {
                ans = newAns;
                parent[mask][pos] = city;
            }
        }
    }

    return DP[mask][pos] = ans;
}

void printPath(int mask, int pos) {
    if(pos == -1) {
        return;
    }
    printPath(mask^(1<<pos), parent[mask][pos]);
    cout << pos << " ";
}

int main() {
    for(int i = 0; i < (1<<n); i++) {
        for(int j = 0; j < n; j++) {
            DP[i][j] = -1;
            parent[i][j] = -1;
        }
    }

    int source_node = 2; // Change source node to 2

    cout << "Minimum Distance Travelled -> " << TSP(1<<source_node, source_node) << "\n";
    cout << "Optimal Tour Path: " << source_node << " ";
    printPath(completed_visit^(1<<source_node), parent[completed_visit][source_node]);
    cout << source_node << "\n";

    return 0;
}
