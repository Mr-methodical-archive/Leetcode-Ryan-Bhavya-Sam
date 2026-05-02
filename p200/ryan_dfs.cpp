class Solution {
    // issue: how do we know when we have a new island:
    //        maybe BFS would be best
    //        Oh, we only return 1 when it is by itself
public:
    bool inbounds(vector<vector<char>>& grid, int r, int c) {
        return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size();
    }

    void zero(vector<vector<char>>& grid, int r, int c) {
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        grid[r][c] = 0;
        for (size_t i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (inbounds(grid, nr, nc) && grid[nr][nc] == '1') {
                zero(grid, nr, nc);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // scan grid to see if any, if all 0's then no islands
        int count = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    zero(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
};
