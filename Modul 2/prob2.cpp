#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Queue q;
    init(&q);

    int jumlah = 0;

    if (k > n) k = n;

    for (int i = 0; i < k; i++) {
        enqueue(&q, arr[i]);
        jumlah += arr[i];
    }

    cout << jumlah;

    for (int i = k; i < n; i++) {
        int depan = front(&q);
        jumlah -= depan;
        dequeue(&q);

        enqueue(&q, arr[i]);
        jumlah += arr[i];

        cout << " " << jumlah;
    }

    cout << endl; 

    return 0;
}