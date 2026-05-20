#include <bits/stdc++.h>
using namespace std;
vector<int> A;
void merge(int low, int hi)
{
    int mid = (low + hi) / 2;
    int m = mid - low + 1;
    int n = hi - mid;
    vector<int> L;
    vector<int> R;

    for (int i = 0; i < m; i++)
        L.push_back(A[low + i]);
    for (int i = 0; i < n; i++)
        R.push_back(A[mid + 1 + i]);

    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    int i = 0, j = 0;
    for (int k = low; k <= hi; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}
void mergesort(int low, int hi)
{
    if (low < hi)
    {
        int mid = (low + hi) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, hi);
        merge(low, hi);
    }
}
int main()
{
    int x, y;
    cout << "Enter array size:";
    cin >> x;
    cout << "Enter array elements:\n";
    for (int i = 0; i < x; i++)
    {
        cin >> y;
        A.push_back(y);
    }

    mergesort(0, A.size() - 1);

    cout << "After merge sort:" << endl;
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}