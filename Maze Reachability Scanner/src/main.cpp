#include <iostream>

using namespace std;

const int MAX_SIZE = 1010;

bool visited[MAX_SIZE][MAX_SIZE];

char grid[MAX_SIZE][MAX_SIZE];

int rows;
int cols;

bool isValid(int x, int y) {

    return (
        x >= 0 &&
        x < rows &&
        y >= 0 &&
        y < cols
    );
}

void dfs(int x, int y) {

    if (!isValid(x, y)) {
        return;
    }

    if (visited[x][y]) {
        return;
    }

    if (grid[x][y] == '#') {
        return;
    }

    visited[x][y] = true;

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {

    cin >> rows >> cols;

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {

            cin >> grid[i][j];
        }
    }

    int startX;
    int startY;

    cin >> startX >> startY;

    dfs(startX, startY);

    int queries;

    cin >> queries;

    while (queries--) {

        int targetX;
        int targetY;

        cin >> targetX >> targetY;

        if (
            isValid(targetX, targetY) &&
            visited[targetX][targetY]
        ) {

            cout << "YES\n";
        }
        else {

            cout << "NO\n";
        }
    }

    return 0;
}