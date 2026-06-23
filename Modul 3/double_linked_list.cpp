#include "double_linked_list.h"
#include <iostream>

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return size == 0;
}

void DoubleLinkedList::add_front(char val) {
    Node* node = new Node;
    node->data = val;

    if (is_empty()) {
        head = tail = node;
        node->next = node->prev = node;
    } else {
        node->next = head;
        node->prev = tail;
        head->prev = node;
        tail->next = node;
        head = node;
    }

    size++;
}

void DoubleLinkedList::add_back(char val) {
    Node* node = new Node;
    node->data = val;

    if (is_empty()) {
        head = tail = node;
        node->next = node->prev = node;
    } else {
        node->prev = tail;
        node->next = head;
        tail->next = node;
        head->prev = node;
        tail = node;
    }

    size++;
}

void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) return;

    if (idx == 0) {
        add_front(val);
        return;
    }

    if (idx == size) {
        add_back(val);
        return;
    }

    Node* cur = head;
    for (int i = 0; i < idx - 1; i++) {
        cur = cur->next;
    }

    Node* node = new Node;
    node->data = val;

    node->next = cur->next;
    node->prev = cur;

    cur->next->prev = node;
    cur->next = node;

    size++;
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) return;

    Node* del = head;

    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }

    delete del;
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) return;

    Node* del = tail;

    if (size == 1) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }

    delete del;
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) return;

    if (is_empty()) return;

    if (idx == 0) {
        delete_front();
        return;
    }

    if (idx == size - 1) {
        delete_back();
        return;
    }

    Node* cur = head;
    for (int i = 0; i < idx; i++) {
        cur = cur->next;
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;

    delete cur;
    size--;
}

char DoubleLinkedList::get(int idx) {
    if (is_empty() || idx < 0 || idx >= size)
        return '\0';

    Node* cur = head;
    for (int i = 0; i < idx; i++) {
        cur = cur->next;
    }

    return cur->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (is_empty() || idx < 0 || idx >= size)
        return;

    Node* cur = head;
    for (int i = 0; i < idx; i++) {
        cur = cur->next;
    }

    cur->data = val;
}

void DoubleLinkedList::display() {
    if (is_empty()) return;

    Node* cur = head;
    do {
        std::cout << cur->data;
        cur = cur->next;
    } while (cur != head);

    std::cout << "\n";
}

void DoubleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}