#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int FR, FC;
int totalJalur = 0;

int baris[] = {-1, 1, 0, 0};
int kolom[] = {0, 0, -1, 1};

void dfs(int r, int c) {
    if (r == FR && c == FC) {
        totalJalur++;
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int barisBaru = r + baris[i];
        int kolomBaru = c + kolom[i];

        if (barisBaru >= 0 && barisBaru < R &&
            kolomBaru >= 0 && kolomBaru < C &&
            grid[barisBaru][kolomBaru] == 0 &&
            !visited[barisBaru][kolomBaru]) {

            dfs(barisBaru, kolomBaru);
        }
    }

    visited[r][c] = false;
}

int main() {
    cin >> R >> C;

    grid.assign(R, vector<int>(C));
    visited.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int SR, SC;

    cin >> SR >> SC;
    cin >> FR >> FC;

    dfs(SR, SC);

    cout << totalJalur << endl;

    return 0;
}