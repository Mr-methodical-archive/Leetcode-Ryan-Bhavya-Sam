class Solution {
public:
    bool inbounds(vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size();
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // every minute is one cycle so must use bfs
        queue<vector<pair<int, int>>> q;
        size_t minutes = 0;
        // go through one loop to identify rotting tomatoes:
        vector<pair<int, int>> start;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    start.push_back({i, j});
                }
            }
        }
        q.push(start);
        int dc[] = {-1, 1, 0, 0};
        int dr[] = {0, 0, -1, 1};
        while (q.front().size() > 0) {
            vector<pair<int, int>> todo = q.front();
            q.pop();
            vector<pair<int, int>> curr;
            for (auto [x, y] : todo) {
                // so we have a current pair, we need to infect the surrounding and add to queue
                for (size_t i = 0; i < 4; ++i) {
                    int nr = x + dr[i];
                    int nc = y + dc[i];
                    if (inbounds(grid, nr, nc) && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        curr.push_back({nr, nc});
                    }
                }
            }
            q.push(curr);
            if (curr.size() > 0) {
                ++minutes;
            }
        }
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes;
    }
};
