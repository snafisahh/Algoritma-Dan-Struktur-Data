#include <iostream>
#include "single_linked_list.h"
using namespace std;

void delete_next(SingleLinkedList &list, Node* prev) {
    if (list.size == 1) {
        delete list.head;
        list.head = nullptr;
        list.tail = nullptr;
        list.size = 0;
        return;
    }

    Node* hapus = prev->next;

    if (hapus == list.head) {
        list.head = list.head->next;
        list.tail->next = list.head;
    }

    if (hapus == list.tail) {
        list.tail = prev;
        list.tail->next = list.head;
    }

    prev->next = hapus->next;
    delete hapus;
    list.size--;
}

int main() {
    int N;
    long long K;
    cin >> N >> K;

    SingleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        list.add_back(x);
    }

    Node* sekarang = list.head;
    Node* prev = list.tail;
    long long awal = K;

    while (list.size > 1) {
        long long langkah = K % list.size;
        if (langkah == 0) langkah = list.size;
        for (long long i = 1; i < langkah; i++) {

            prev = sekarang;
            sekarang = sekarang->next;
        }

        int nilai = sekarang->data;
        delete_next(list, prev);

        if (nilai % 2 == 0) K++;
        else K--;

        if (K <= 0) K = awal;

        sekarang = prev->next;
    }

    cout << list.head->data;
    return 0;
}