//
// Created by divan on 10/6/23.
//
#include <iostream>
#include <ctime>

using namespace std;

void bubbleSorting(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int n = 10;
    int arr[n];

    srand(time(0));
    for (int &i: arr) {
        i = rand() % 100;
    }

    cout << "Исходный массив:\n";
    for (int i: arr) {
        cout << i << " ";
    }

    cout << endl;

    bubbleSorting(arr, n);

    cout << "Отсортированный массив:\n";
    for (int i: arr) {
        cout << i << " ";
    }

    return 0;
}

// немного скучно, я буду писать hot keys, которые случайно обнаруживаю в процессе написания кода)
// ctrl + alt + ; = смайлики 🥰🥺