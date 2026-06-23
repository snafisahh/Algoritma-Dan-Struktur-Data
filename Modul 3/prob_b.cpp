#include <iostream>
#include "double_linked_list.h"
using namespace std;

int main() {
    int N, R;
    if (!(cin >> N >> R)) return 0;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        list.add_back(c);
    }

    Node* alpha = list.head; 
    Node* beta = list.tail; 

    for (int i = 0; i < R; i++) {
        long long X, Y;
        if (!(cin >> X >> Y)) break;

        if (list.size == 0) break;

        long long m1 = X % list.size;
        for (long long j = 0; j < m1; j++) {
            alpha = alpha->next;
        }

        long long m2 = Y % list.size;
        for (long long j = 0; j < m2; j++) {
            beta = beta->prev;
        }

        if (alpha == beta) {
            Node* d = alpha; 
            
            if (list.size == 1) {
                delete d;
                list.head = nullptr;
                list.tail = nullptr;
                list.size = 0;
                alpha = nullptr;
                beta = nullptr;
            } else {
                alpha = d->next;
                beta = d->prev;

                d->prev->next = d->next;
                d->next->prev = d->prev;

                if (list.head == d) list.head = d->next;
                if (list.tail == d) list.tail = d->prev;

                delete d;
                list.size--;
            }
        } 
        else if (alpha->next == beta || alpha->prev == beta) {
        
            bool ujung = (alpha == list.head && beta == list.tail) ||
                         (alpha == list.tail && beta == list.head);

            if (!(ujung && list.size > 2)) {
                char t = alpha->data;
                alpha->data = beta->data;
                beta->data = t;
            }
        }
    }

    if (list.size == 0) {
        cout << "EMPTY\n";
    } else {
        Node* p = list.head;
        for (int i = 0; i < list.size; i++) {
            cout << p->data;
            p = p->next;
        }
        cout << "\n";
    }

    list.clear();
    return 0;
}