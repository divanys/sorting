//
// Created by divan on 10/6/23.
//

// Начало в алгоритме Сортировка выбором с каждым шагом цикла смещается в сторону хвоста массива.
// Поэтому на первой итерации цикла, найденное минимальное значение меняется местами со значением в нулевой ячейке массива.
// На второй итерации “начало” уже будет указывать на следующую (первую) ячейку и так далее.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void selectionSorting(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] >= arr[minIndex]) continue;
            minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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

    selectionSorting(arr, n);

    cout << "\nОтсортированный массив:\n";
    for (int i: arr) {
        cout << i << " ";
    }

    return 0;
}

// alt + ⬆/⬇ - переместиться через функцию/метод
// alt + ⬅/➡ - переместиться через открытые файлы