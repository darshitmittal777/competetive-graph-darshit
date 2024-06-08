#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(vector<vector<int>> &map, int a, int b, vector<vector<int>> &check, vector<vector<int>> &level) {
    queue<pair<int, int>> q;
    q.push({a, b});
    check[a][b] = 1;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        map[x][y] = 3;  // Mark current cell as visited

        // Check all four possible directions
        if (x + 1 < map.size() && check[x + 1][y] == 0) {
            if (map[x + 1][y] == 2) return level[x][y] + 1; // Destination found
            if (map[x + 1][y] == 0) {
                q.push({x + 1, y});
                check[x + 1][y] = 1;
                level[x + 1][y] = level[x][y] + 1;
            }
        }
        if (y + 1 < map[0].size() && check[x][y + 1] == 0) {
            if (map[x][y + 1] == 2) return level[x][y] + 1; // Destination found
            if (map[x][y + 1] == 0) {
                q.push({x, y + 1});
                check[x][y + 1] = 1;
                level[x][y + 1] = level[x][y] + 1;
            }
        }
        if (x - 1 >= 0 && check[x - 1][y] == 0) {
            if (map[x - 1][y] == 2) return level[x][y] + 1; // Destination found
            if (map[x - 1][y] == 0) {
                q.push({x - 1, y});
                check[x - 1][y] = 1;
                level[x - 1][y] = level[x][y] + 1;
            }
        }
        if (y - 1 >= 0 && check[x][y - 1] == 0) {
            if (map[x][y - 1] == 2) return level[x][y] + 1; // Destination found
            if (map[x][y - 1] == 0) {
                q.push({x, y - 1});
                check[x][y - 1] = 1;
                level[x][y - 1] = level[x][y] + 1;
            }
        }
    }
    return -1; // No path found
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    int x, y; // Coordinates of the starting point 'A'

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char a;
            cin >> a;
            if (a == '#')
                map[i][j] = -1;
            else if (a == 'A') {
                x = i;
                y = j;
                map[i][j] = 1;
            }
            else if (a == 'B')
                map[i][j] = 2;
            else if (a == '.')
                map[i][j] = 0;
        }
    }

    vector<vector<int>> check(n, vector<int>(m, 0));
    vector<vector<int>> level(n, vector<int>(m, 0));

    cout << solve(map, x, y, check, level) << endl;

    return 0;
}
