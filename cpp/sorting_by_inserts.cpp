//
// Created by divan on 10/6/23.
//
#include <iostream>
#include <ctime>

using namespace std;

void insertionSort(int *arr, int n) {
    int counter = 0;
    for (int i = 1; i < n; i++) {  // сортировка начинается со второго элемента массива (индекс 1)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            counter++;
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];  // просто меняем элементы местами
            arr[j] = tmp;
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

    insertionSort(arr, n);

    cout << "\nОтсортированный массив:\n";
    for (int i: arr) {
        cout << i << " ";
    }

    return 0;
}

// ctrl + l = поиск символов/слов в коде
// повторное нажатие - "хождение" по файлу вперёд, обнаруживая введённые символы
// ctrl + shift + l - "хождение" по файлу назад, обнаруживая введённые символы