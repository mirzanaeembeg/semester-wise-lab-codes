#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> l, vector<int> r)
{
    vector<int> a;
    int m = l.size();
    int n = r.size();
    l.push_back(INT_MAX);
    r.push_back(INT_MAX);
    int i = 0, j = 0;
    for (int k = 0; k < m + n; k++)
    {
        if (l[i] <= r[j])
        {
            a.push_back(l[i]);
            i++;
        }
        else
        {
            a.push_back(r[j]);
            j++;
        }
    }
    cout << "After merging:\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int x, m, n;
    vector<int> p, q;
    cout << "Enter vector size:\n";
    cin >> m >> n;
    cout << "Enter first vector element:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    cout << "Enter second vector element:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push_back(x);
    }
    merge(p, q);
    return 0;
}