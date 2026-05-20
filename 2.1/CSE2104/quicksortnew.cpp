#include <bits/stdc++.h>
using namespace std;


int Partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the pivot as the last element
    int i = low - 1; // Index of the smaller element
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    
    swap(arr[i + 1], arr[high]); // Swap the pivot with the element at i + 1
    return i + 1; // Return the index of the pivot after rearranging
}

// Function to perform Quick Sort
void QuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high); // Partition the array
        
        // Recursively sort the subarrays on both sides of the pivot
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    QuickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
