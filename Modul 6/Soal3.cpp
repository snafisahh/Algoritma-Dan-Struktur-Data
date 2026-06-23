#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int SR, SC;
    int FR, FC;

    cin >> SR >> SC;
    cin >> FR >> FC;

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<pair<pair<int, int>, int>> q;

    q.push({{SR, SC}, 0});
    visited[SR][SC] = true;

    int baris[] = {-1, 1, 0, 0};
    int kolom[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int jarak = q.front().second;
        q.pop();

        if (r == FR && c == FC) {
            cout << jarak << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + baris[i];
            int nc = c + kolom[i];

            if (nr >= 0 && nr < R &&
                nc >= 0 && nc < C &&
                grid[nr][nc] == 0 &&
                !visited[nr][nc]) {

                visited[nr][nc] = true;
                q.push({{nr, nc}, jarak + 1});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}