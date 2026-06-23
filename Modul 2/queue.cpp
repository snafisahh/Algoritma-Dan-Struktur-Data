#include "queue.h"

void init(Queue* q) {
    q->front = q->data;
    q->rear = q->data;
}

bool isEmpty(const Queue* q) {
    return q->front == q->rear;
}

bool isFull(const Queue* q) {
    return (q->rear - q->data) == MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw "queue penuh";
    }
    *(q->rear) = value;
    q->rear++;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong";
    }

    for (int* p = q->front; p < q->rear - 1; ++p) {
        *p = *(p + 1);
    }

    q->rear--;
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong";
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong";
    }
    return *(q->rear - 1);
}