#include <bits/stdc++.h>
using namespace std;

vector<int> Merge(vector<int>& left_arr,vector<int>& right_arr) {
    vector<int> merged;
    int i = 0;
    int j = 0;

    while (i < left_arr.size() && j < right_arr.size()) {
        if (left_arr[i] <= right_arr[j]) {
            merged.push_back(left_arr[i]);
            i++;
        } else {
            merged.push_back(right_arr[j]);
            j++;
        }
    }

    while (i < left_arr.size()) {
        merged.push_back(left_arr[i]);
        i++;
    }

    while (j < right_arr.size()) {
        merged.push_back(right_arr[j]);
        j++;
    }

    return merged;
}

vector<int> MergeSort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;  // Base case: Already sorted or single element
    }

    int middle = arr.size() / 2;
    vector<int> left_half(arr.begin(), arr.begin() + middle);
    vector<int> right_half(arr.begin() + middle, arr.end());

    vector<int> left_sorted = MergeSort(left_half);
    vector<int> right_sorted = MergeSort(right_half);

    return Merge(left_sorted, right_sorted);
}

int main() {
    vector<int> unsorted_array = {12, 29, 5, 8, 18, 7};
    
    vector<int> sorted_array = MergeSort(unsorted_array);

    cout << "Sorted Array: ";
    for (int num : sorted_array) {
        cout << num << " ";
    }

    return 0;
}
