#include <iostream>

using namespace std;

/*
=================================================
            Grid Path Finder Using DFS
=================================================
*/

const int MAX_SIZE = 1010;

bool visited[MAX_SIZE][MAX_SIZE];

char grid[MAX_SIZE][MAX_SIZE];

int rows;
int cols;

/*
=================================================
                Check Valid Cell
=================================================
*/
bool isValid(int x, int y) {

    return (
        x >= 0 &&
        x < rows &&
        y >= 0 &&
        y < cols
    );
}

/*
=================================================
                DFS Traversal
=================================================
*/
void dfs(int x, int y) {

    // Out of bounds
    if (!isValid(x, y)) {
        return;
    }

    // Already visited
    if (visited[x][y]) {
        return;
    }

    // Wall cell
    if (grid[x][y] == '#') {
        return;
    }

    visited[x][y] = true;

    // Explore neighbors
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

/*
=================================================
                    MAIN
=================================================
*/
int main() {

    cin >> rows >> cols;

    /*
    =============================================
                Input Grid
    =============================================
    */
    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {

            cin >> grid[i][j];
        }
    }

    int startX;
    int startY;

    cin >> startX >> startY;

    /*
    =============================================
            Run DFS From Start Cell
    =============================================
    */
    dfs(startX, startY);

    int queries;

    cin >> queries;

    /*
    =============================================
            Answer Reachability Queries
    =============================================
    */
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
