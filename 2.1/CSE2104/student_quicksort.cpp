#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

struct student {
    string name;
    int id;
    float cgpa;
};

student s[3];

int Partition(int low, int high) {
    student pivot = s[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (s[i].cgpa > pivot.cgpa || (s[i].cgpa == pivot.cgpa && s[i].name > pivot.name)) {
            i++;
        }
        while (s[j].cgpa < pivot.cgpa || (s[j].cgpa == pivot.cgpa && s[j].name < pivot.name)) {
            j--;
        }
        if (i < j) {
            swap(s[i], s[j]);
        }
    }

    swap(s[low], s[j]);
    return j;
}

void quicksort(int low, int high) {
    if (low < high) {
        int pivot = Partition(low, high);
        quicksort(low, pivot - 1);
        quicksort(pivot + 1, high);
    }
}

int main() {
    cout << "Enter student details:\n";

    for (int i = 0; i < 3; i++) {
        cin >> s[i].name >> s[i].id >> s[i].cgpa;
    }

    quicksort(0, 2);

    cout << "Quick sorted student details:\n";

    for (int i = 0; i < 3; i++) {
        cout << "Name: " << s[i].name << endl;
        cout << "ID: " << s[i].id << endl;
        cout << "CGPA: " << s[i].cgpa << endl;
    }

    return 0;
}
