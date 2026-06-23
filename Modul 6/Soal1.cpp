#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> vertex(N);
    for (int i = 0; i < N; i++) {
        cin >> vertex[i];
    }

    vector<vector<int>> adjMatrix(N, vector<int>(N, 0));

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        char U, V;
        int W;
        cin >> U >> V >> W;

        int baris = -1;
        int kolom = -1;

        for (int j = 0; j < N; j++) {
            if (vertex[j] == U) baris = j;
            if (vertex[j] == V) kolom = j;
        }

        adjMatrix[baris][kolom] = W;
    }

    cout << "Adjacency Matrix:" << endl;
    cout << " ";
    for (int i = 0; i < N; i++) {
        cout << " " << vertex[i];
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << vertex[i];
        for (int j = 0; j < N; j++) {
            cout << " " << adjMatrix[i][j];
        }
        cout << endl;
    }

    return 0;
}