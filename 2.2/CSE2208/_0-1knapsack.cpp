#include<bits/stdc++.h>
using namespace std;

void knapsack(int p[], int wt[], int m, int n) {
    int k[n+1][m+1];

    // Dynamic programming approach to fill the knapsack table
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= m; w++){
            if(i == 0 || w == 0)
                k[i][w] = 0;
            else if(wt[i] <= w){
                k[i][w] = max(p[i] + k[i-1][w-wt[i]], k[i-1][w]);
            }
            else
                k[i][w] = k[i-1][w];
        }
    }

    // Printing the items included in the knapsack
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(k[i][j] != k[i-1][j]){
            cout << i << " = 1" << endl;
            j = j - wt[i];
        }
        i--;
    }
}

int main(){
    int p[5] = {0, 1, 2, 5, 6};
    int wt[5] = {0, 2, 3, 4, 5};
    int m = 8, n = 4;

    knapsack(p, wt, m, n);

    return 0;
}
