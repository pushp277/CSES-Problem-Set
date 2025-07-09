#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> grid;
vector<vector<bool>> visited;

string solve() {
    vector<pair<int, int>> frontier = {{0, 0}};
    string result;
    visited[0][0] = true;
    result += grid[0][0];

    while (!frontier.empty()) {
        vector<pair<int, int>> next;
        char min_char = 'Z' + 1;

        // Step 1: Find minimum next character
        for (auto [x, y] : frontier) {
            for (auto [dx, dy] : {pair{1, 0}, pair{0, 1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < n && ny < n && !visited[nx][ny]) {
                    min_char = min(min_char, grid[nx][ny]);
                }
            }
        }

        // Step 2: Collect all positions with that minimum character
        for (auto [x, y] : frontier) {
            for (auto [dx, dy] : {pair{1, 0}, pair{0, 1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < n && ny < n && !visited[nx][ny] && grid[nx][ny] == min_char) {
                    visited[nx][ny] = true;
                    next.emplace_back(nx, ny);
                }
            }
        }

        if (!next.empty()) {
            result += min_char;
            frontier = move(next);
        } else {
            break;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    grid.resize(n);
    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    cout << solve() << '\n';
}
