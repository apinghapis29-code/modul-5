# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Hafis Saputra - 109082500087</p>

## Dasar Teori

### A. Singly Linked List

Singly linked list merupakan struktur data yang terdiri dari node-node yang saling terhubung melalui pointer. Setiap node memiliki bagian `info` untuk menyimpan data dan `next` untuk menunjuk node berikutnya. Node pertama ditunjuk oleh `first`, sedangkan node terakhir menunjuk ke `nullptr`. Struktur ini bersifat dinamis karena node dapat ditambahkan atau dihapus sesuai kebutuhan program [1].

### B. Searching pada Linked List

Searching merupakan proses mencari data tertentu dengan menelusuri node dari awal list satu per satu. Pencarian berhenti ketika data yang dicari ditemukan. Jika penelusuran sudah mencapai `nullptr` dan data belum ditemukan, fungsi mengembalikan nilai `nullptr`. Pada Modul 5, fungsi `findElm(L, x)` digunakan untuk mencari node yang memiliki nilai `info` sama dengan `x` [2].

### C. Pointer dan Pengelolaan Memori

Pointer menyimpan alamat suatu data di memori. Dalam singly linked list, pointer digunakan untuk mengakses isi node dan berpindah ke node berikutnya. Fungsi `alokasi()` membuat node baru menggunakan `new`, sedangkan `dealokasi()` menghapus node menggunakan `delete`. Pengelolaan memori diperlukan agar node yang sudah tidak digunakan tidak tetap memenuhi memori program [1].

### D. Penjumlahan Data pada Linked List

Selain menelusuri list untuk mencari nilai, program dapat mengunjungi setiap node dan menjumlahkan nilai `info` yang tersimpan. Proses dilakukan dengan menambahkan nilai node ke variabel total, kemudian menggeser pointer ke node berikutnya hingga mencapai akhir list. Pada data latihan Modul 5, nilai yang dijumlahkan adalah 9, 12, 8, 0, dan 2 sehingga totalnya 31 [2].

## Guided

### 1. Singlylist.h

```cpp
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertFirst(List &L, address P);
address findElm(const List &L, infotype x);
int totalInfo(const List &L);

#endif
```

File `Singlylist.h` berisi deklarasi tipe data dan fungsi yang dipakai dalam program. `infotype` ditetapkan sebagai integer, sedangkan `address` merupakan pointer ke `ElmList`. Struktur `ElmList` memiliki data `info` dan pointer `next`, sementara struktur `List` menyimpan pointer `first`. Prototipe `findElm()` dan `totalInfo()` ditambahkan untuk mendukung soal pencarian dan penjumlahan nilai.

### 2. Singlylist.cpp

```cpp
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
```

File implementasi berisi fungsi-fungsi yang telah dideklarasikan di header. `createList()` membuat list kosong, `alokasi()` membuat node baru, dan `insertFirst()` memasukkan node di awal list. Fungsi `printInfo()` menampilkan seluruh data. Fungsi `findElm()` menelusuri node untuk mencari nilai tertentu, sedangkan `totalInfo()` menjumlahkan semua nilai pada setiap node.

### 3. main.cpp

```cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi linked list: ";
    printInfo(L);

    address hasil = findElm(L, 8);
    if (hasil != nullptr) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "Data tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah "
         << totalInfo(L) << endl;

    while (L.first != nullptr) {
        address Hapus = L.first;
        L.first = L.first->next;
        dealokasi(Hapus);
    }

    return 0;
}
```

Program utama membuat lima node berisi nilai 2, 0, 8, 12, dan 9. Karena setiap node dimasukkan menggunakan `insertFirst()`, urutan data yang terbentuk dari awal list adalah 9, 12, 8, 0, dan 2. Setelah list ditampilkan, program mencari nilai 8 dan menjumlahkan seluruh nilai node. Sebelum program selesai, semua node dihapus untuk membebaskan memori.

## Unguided

### 1. Latihan 1 — Membuat dan Menampilkan Singly Linked List

Pada latihan pertama, ADT singly linked list dibuat menggunakan tiga file, yaitu `Singlylist.h`, `Singlylist.cpp`, dan `main.cpp`. Data dimasukkan menggunakan fungsi `alokasi()` dan `insertFirst()`. Urutan data pada list menjadi `9 -> 12 -> 8 -> 0 -> 2` karena setiap elemen baru diletakkan pada bagian awal list.

**Output latihan 1:**
link output : https://github.com/apinghapis29-code/modul-5/blob/01584783cfc44946e0115ed2dd46978445e9c7aa/Cuplikan%20layar%202026-10-25%20193056.png
```text
Isi linked list: 9 12 8 0 2
```

Hasil tersebut sesuai dengan ilustrasi dan output yang ditampilkan pada Modul 5 halaman 49–50. Penggunaan pointer `first` dan `next` membuat setiap node terhubung hingga node terakhir yang menunjuk ke `nullptr` [2].

### 2. Latihan 2 — Mencari Elemen Bernilai 8

Soal meminta pencarian elemen dengan nilai `info` sebesar 8 melalui fungsi `findElm(L, x)`. Fungsi dimulai dari node pertama, kemudian membandingkan nilai `info` setiap node dengan nilai yang dicari. Jika nilainya sama, alamat node dikembalikan dan pencarian dihentikan. Jika tidak ditemukan sampai akhir list, fungsi mengembalikan `nullptr`.

**Output latihan 2:**
link output: https://github.com/apinghapis29-code/modul-5/blob/01584783cfc44946e0115ed2dd46978445e9c7aa/Cuplikan%20layar%202026-10-25%20193056.png
```text
8 ditemukan dalam list
```

Hasil tersebut menunjukkan bahwa nilai 8 terdapat pada list, tepatnya di antara node bernilai 12 dan 0. Fungsi pencarian tidak mengubah susunan list karena hanya membaca nilai dan mengikuti pointer `next` [2].

### 3. Latihan 3 — Menghitung Total Nilai Semua Elemen

Latihan berikutnya meminta program menjumlahkan semua nilai pada list, yaitu 9 + 12 + 8 + 0 + 2. Fungsi `totalInfo()` menggunakan variabel `total` yang awalnya bernilai nol. Program menelusuri seluruh node, menambahkan `info` ke `total`, lalu berpindah ke node berikutnya sampai pointer bernilai `nullptr`.

Perhitungannya adalah 9 + 12 + 8 + 0 + 2 = 31.

**Output latihan 3:**
output : https://github.com/apinghapis29-code/modul-5/blob/01584783cfc44946e0115ed2dd46978445e9c7aa/Cuplikan%20layar%202026-10-25%20193056.png
```text
Total info dari kelima elemen adalah 31
```

Output tersebut sesuai dengan hasil yang diharapkan pada Modul 5 halaman 50. Nilai 0 tetap dilewati dalam arti tidak mengubah hasil penjumlahan, tetapi node tersebut tetap menjadi bagian dari list dan tetap dikunjungi oleh program [2].

### 4. Hasil Pengujian Program Secara Keseluruhan

Program telah dikompilasi dan dijalankan menggunakan compiler C++. Hasil keluaran lengkapnya sebagai berikut.
link output:  https://github.com/apinghapis29-code/modul-5/blob/01584783cfc44946e0115ed2dd46978445e9c7aa/Cuplikan%20layar%202026-10-25%20193056.png
```text
Isi linked list: 9 12 8 0 2
8 ditemukan dalam list
Total info dari kelima elemen adalah 31
```

Dari hasil pengujian, program berhasil menampilkan isi linked list, menemukan elemen bernilai 8, dan menghitung jumlah total data sebesar 31. Hasil ini sesuai dengan tujuan latihan pada Modul 5. Penambahan fungsi pencarian dan penjumlahan juga memperlihatkan bahwa satu struktur linked list dapat digunakan untuk beberapa proses tanpa perlu menyusun ulang data.

## Kesimpulan

1. Singly linked list menyimpan data dalam node yang terhubung melalui pointer `next`, sehingga data dapat ditelusuri dari node pertama sampai node terakhir.
2. Fungsi `findElm()` dapat digunakan untuk mencari elemen bernilai 8 dengan menelusuri list secara berurutan.
3. Fungsi `totalInfo()` berhasil menjumlahkan seluruh nilai node, yaitu 9 + 12 + 8 + 0 + 2 = 31, sesuai dengan output yang diharapkan dalam modul.

## Referensi