#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key) {  // Change the comparison to 'less than' for descending order
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    cout << "After insertion sort in descending order:\n";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}

int main() {
    vector<int> v;
    int n, y;
    cout << "Enter size:\n";
    cin >> y;
    cout << "Enter array elements:\n";
    for (int i = 0; i < y; i++) {
        cin >> n;
        v.push_back(n);
    }
    insertionSort(v);
    return 0;
}
