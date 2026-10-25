#include <iostream>
#include "Singlylist.h"
using namespace std;

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void printInfo(const List &L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->info;
        if (P->next != nullptr) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (P == nullptr) return;
    P->next = L.first;
    L.first = P;
}

address findElm(const List &L, infotype x) {
    address P = L.first;
    while (P != nullptr) {
        if (P->info == x) return P;
        P = P->next;
    }
    return nullptr;
}

int totalInfo(const List &L) {
    int total = 0;
    address P = L.first;
    while (P != nullptr) {
        total += P->info;
        P = P->next;
    }
    return total;
}
