#include <bits/stdc++.h>
using namespace std;
int bin_search(vector<int> a, int k)
{
    int low = 0;
    int hi = a.size() - 1;
    while (low <= hi)
    {
        int mid = (low + hi) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            low = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}
int main()
{
    vector<int> v;
    int x, y, key;
    cout << "Enter array size:\n";
    cin >> y;
    cout << "Enter array elements:\n";
    for (int i = 0; i < y; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << "Enter key:\n";
    cin >> key;
    int ans = bin_search(v, key);
    if (ans == -1)
        cout << "Not Found" << endl;
    else
        cout << "Data is at index:" << ans << endl;

    return 0;
}