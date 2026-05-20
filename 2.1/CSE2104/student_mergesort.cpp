#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct student {
    string name;
    int id;
    float cgpa;
};

vector<student> s;

void merge(int low, int mid, int hi) {
    int leftSize = mid - low + 1;
    int rightSize = hi - mid;
    vector<student> left(leftSize);
    vector<student> right(rightSize);

    for (int i = 0; i < leftSize; i++)
        left[i] = s[low + i];
    for (int i = 0; i < rightSize; i++)
        right[i] = s[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < leftSize && j < rightSize) {
        if (left[i].cgpa > right[j].cgpa || (left[i].cgpa == right[j].cgpa && left[i].name < right[j].name)) {
            s[k] = left[i];
            i++;
        } else {
            s[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        s[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        s[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int low, int hi) {
    if (low < hi) {
        int mid = low + (hi - low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, hi);
        merge(low, mid, hi);
    }
}

int main() {
    cout << "Enter student details:\n";

    for (int i = 0; i < 3; i++) {
        student newStudent;
        cin >> newStudent.name >> newStudent.id >> newStudent.cgpa;
        s.push_back(newStudent);
    }

    mergeSort(0, s.size() - 1);

    cout << "Merge sorted student details:\n";

    for (int i = 0; i < 3; i++) {
        cout << "Name: " << s[i].name << endl;
        cout << "ID: " << s[i].id << endl;
        cout << "CGPA: " << s[i].cgpa << endl;
    }

    return 0;
}
