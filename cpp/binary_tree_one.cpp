//
// Created by divan on 10/6/23.
//
// бинарное дерево. принцип: Если значение узла больше добавляемого – добавляется ветка справа, иначе создается ветка слева.
#include <iostream>
#include <ctime>

using namespace std;

int tabs = 0;

struct Branch {
    int Data;
    Branch *LeftBranch;
    Branch *RightBranch;
};

void Add(int aData, Branch *&aBranch) {
    if (!aBranch) {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = nullptr;
        aBranch->RightBranch = nullptr;
        return;
    } else if (aBranch->Data > aData) {
        Add(aData, aBranch->LeftBranch);
    } else {
        Add(aData, aBranch->RightBranch);
    }
}

void print(Branch *aBranch) {
    if (!aBranch) return;
    tabs++;

    print(aBranch->LeftBranch);

    for (int i = 0; i < tabs; i++) cout << " ";
    cout << aBranch->Data << endl;

    print(aBranch->RightBranch);

    tabs--;
}

void FreeTree(Branch *aBranch) {
    if (!aBranch) return;
    FreeTree(aBranch->LeftBranch);
    FreeTree(aBranch->RightBranch);
    delete aBranch;
}

int main() {
    Branch *Root = nullptr;

    srand(time(0));

    const int numRandomValues = 10;

    for (int i = 0; i < numRandomValues; i++) {
        int randomValue = rand() % 100;
        cout << randomValue << " ";
        Add(randomValue, Root);
    }

    cout << endl << endl;
    print(Root);
    FreeTree(Root);

    return 0;
}

// ctrl + w - выделение области
// повторное нажатие - выделение большей и большей области
// ctrl + shift + w - unвыделение области
