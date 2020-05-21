#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void bubbleSort(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> vec;
    ifstream file("file.txt");

    string a;
    string b;
    int s;
    while (!file.eof()) {
        file>>a;
        char p[a.length()];
        for (int i = 0; i < sizeof(p); i++) {
            p[i] = a[i];
        }
        b=p;
        s=atoi(b.c_str());
        vec.push_back(s);
    }

    int arr[vec.size()];
    for (int i = 0; i < vec.size(); i++) {
        arr[i] = vec[i];
    }

    bubbleSort(arr, vec.size());

    for (int i: arr) {
        cout << i<<" ";
    }
}

