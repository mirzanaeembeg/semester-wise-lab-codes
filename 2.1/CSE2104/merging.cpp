#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& array1,vector<int>& array2) {
    vector<int> merged;
    int i = 0;
    int j = 0;

    while (i < array1.size() && j < array2.size()) {
        if (array1[i] <= array2[j]) {
            merged.push_back(array1[i]);
            i++;
        } else {
            merged.push_back(array2[j]);
            j++;
        }
    }

    while (i < array1.size()) {
        merged.push_back(array1[i]);
        i++;
    }

    while (j < array2.size()) {
        merged.push_back(array2[j]);
        j++;
    }

    return merged;
}

int main() {
    vector<int> array1 = {2, 5, 8, 10};
    vector<int> array2 = {3, 7, 9, 12, 15};

    vector<int> merged = merge(array1, array2);

    cout << "Merged Sorted Array: ";
    for (int num : merged) {
        cout << num << " ";
    }
    
    return 0;
}
