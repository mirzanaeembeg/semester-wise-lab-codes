#include <iostream>
#include <vector>
using namespace std;

#define MAX 9999
int n = 4;
int distan[20][20] = {{0, 6, 10, 12},
                      {2, 0, 5, 6},
                      {3, 9, 0, 8},
                      {4, 4, 5, 0}};
int completed_visit = (1 << n) - 1;
int DP[32][8];
int parent[32][8];

int TSP(int mask, int pos)
{
    if (mask == completed_visit)
    {
        return distan[pos][2];
    }
    if (DP[mask][pos] != -1)
    {
        return DP[mask][pos];
    }

    int ans = MAX;

    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = distan[pos][city] + TSP(mask | (1 << city), city);
            if (newAns < ans)
            {
                ans = newAns;
                parent[mask][pos] = city;
            }
        }
    }

    return DP[mask][pos] = ans;
}

void printPath(int mask, int pos)
{
    if (pos == -1)
    {
        return;
    }
    printPath(mask ^ (1 << pos), parent[mask][pos]);
    cout << pos << " ";
}

int main()
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            DP[i][j] = -1;
            parent[i][j] = -1;
        }
    }

    cout << "Minimum Distance Travelled -> " << TSP(1 << 2, 2) << "\n";
    cout << "Optimal Tour Path: 2 ";
    printPath(completed_visit ^ 1 << 2, parent[completed_visit][2]);
    cout << "2\n";

    return 0;
}
