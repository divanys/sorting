//
// Created by divan on 10/6/23.
//
// самое простое объяснение:
// Эти два вложенных цикла поочередно просматривают массив в обе стороны (слева направо, а затем справа налево),
// обменивая элементы при необходимости. Этот процесс повторяется до тех пор, пока левая граница не дойдет до правой,
// что гарантирует корректную сортировку всего массива.
#include <iostream>
#include <cstdlib>

using namespace std;

// функция для обмена значений ячеек
void swapEl(int *arr, int i) {
    int buff;
    buff = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = buff;
}

// функция "шейкер"-сортировки
void myShakerSort(int *arr, int size) {
    int leftMark = 1;
    int rightMark = size - 1;

    while (leftMark <= rightMark) {
        for (int i = rightMark; i >= leftMark; i--) {
            if (arr[i - 1] > arr[i]) swapEl(arr, i);
        }
        leftMark++;

        for (int i = leftMark; i <= rightMark; i++) {
            if (arr[i - 1] > arr[i]) swapEl(arr, i);
        }
        rightMark--;
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

    myShakerSort(arr, n);

    cout << "\nОтсортированный массив:\n";
    for (int i: arr) {
        cout << i << " ";
    }

    return 0;
}

// shift + f6 - переименовать переменную во всём коде (рефакторинг)