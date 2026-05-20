#include <bits/stdc++.h>
using namespace std;

void insert_value(vector<int>& arr, int val) {
    int j = arr.size() - 1;  // Index of the last element in the sorted portion
    
    while (j >= 0 && arr[j] > val) {
        arr[j + 1] = arr[j];  // Move elements to the right
        j = j - 1;
    }
    
    arr[j + 1] = val;  // Insert the new value into the correct position
}

int main() {
    vector<int> array = {12, 16, 20, 24, 28};  // Sorted array
    
    int new_value = 18;  // Value to insert
    insert_value(array, new_value);
    
    cout << "Array after inserting " << new_value << ": ";
    for (int num : array) {
        cout << num << " ";
    }
    
    return 0;
}
