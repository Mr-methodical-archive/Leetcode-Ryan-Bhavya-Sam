class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int count) {
        // our current one we are on is good
        // we need to put immediate surroundings to count if they are land:
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            int cr = r + dr[i];
            int cc = c + dc[i];
            if (!(cr >= 0 && cc >= 0 && cr < grid.size() && cc < grid[0].size())) {
                // out of bounds
                continue;
            }
            if (grid[cr][cc] == -1) continue;
            else if (grid[cr][cc] == 0) {
                dfs(grid, cr, cc, 1);
            } else if (grid[cr][cc] == INT_MAX) {
                grid[cr][cc] = count;
                dfs(grid, cr, cc, count + 1);
            } else {
                // case grid[cr][cc] greater than 0 but less than INT_MAX:
                grid[cr][cc] = min(grid[cr][cc], count);
                // continue to check out surroundings:
                dfs(grid, cr, cc, count + 1);
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // only recurse when we found treasure
                if (grid[i][j] == 0) {
                    dfs(grid, i, j, 1);
                }
            }
        }
    }
};

