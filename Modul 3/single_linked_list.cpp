#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return head == nullptr;
}

void SingleLinkedList::add_front(int val) {
    Node* baru = new Node;
    baru->data = val;

    if (is_empty()) {
        head = tail = baru;
        baru->next = head;
    } else {
        baru->next = head;
        head = baru;
        tail->next = head;
    }

    size++;
}

void SingleLinkedList::add_back(int val) {
    Node* baru = new Node;
    baru->data = val;

    if (is_empty()) {
        head = tail = baru;
        baru->next = head;
    } else {
        baru->next = head;
        tail->next = baru;
        tail = baru;
    }

    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) {
        throw out_of_range("Index invalid");
    }

    if (idx == 0) {
        add_front(val);
        return;
    }

    if (idx == size) {
        add_back(val);
        return;
    }

    Node* bantu = head;

    for (int i = 0; i < idx - 1; i++) {
        bantu = bantu->next;
    }

    Node* baru = new Node;
    baru->data = val;

    baru->next = bantu->next;
    bantu->next = baru;

    size++;
}

void SingleLinkedList::delete_front() {
    if (is_empty()) {
        throw runtime_error("List kosong");
    }

    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* hapus = head;
        head = head->next;
        tail->next = head;

        delete hapus;
    }

    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) {
        throw runtime_error("List kosong");
    }

    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* bantu = head;

        while (bantu->next != tail) {
            bantu = bantu->next;
        }

        bantu->next = head;

        delete tail;
        tail = bantu;
    }

    size--;
}

void SingleLinkedList::delete_idx(int idx) {
    if (is_empty()) {
        throw runtime_error("List kosong");
    }

    if (idx < 0 || idx >= size) {
        throw out_of_range("Index invalid");
    }

    if (idx == 0) {
        delete_front();
        return;
    }

    if (idx == size - 1) {
        delete_back();
        return;
    }

    Node* bantu = head;

    for (int i = 0; i < idx - 1; i++) {
        bantu = bantu->next;
    }

    Node* hapus = bantu->next;

    bantu->next = hapus->next;

    delete hapus;

    size--;
}

void SingleLinkedList::display() {
    if (is_empty()) {
        cout << "Kosong";
        return;
    }

    Node* bantu = head;

    do {
        cout << bantu->data << " ";
        bantu = bantu->next;
    } while (bantu != head);

    cout << endl;
}

int SingleLinkedList::get(int idx) {
    if (is_empty()) {
        throw runtime_error("List kosong");
    }

    if (idx < 0 || idx >= size) {
        throw out_of_range("Index invalid");
    }

    Node* bantu = head;

    for (int i = 0; i < idx; i++) {
        bantu = bantu->next;
    }

    return bantu->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (is_empty()) {
        throw runtime_error("List kosong");
    }

    if (idx < 0 || idx >= size) {
        throw out_of_range("Index invalid");
    }

    Node* bantu = head;

    for (int i = 0; i < idx; i++) {
        bantu = bantu->next;
    }

    bantu->data = val;
}

void SingleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}