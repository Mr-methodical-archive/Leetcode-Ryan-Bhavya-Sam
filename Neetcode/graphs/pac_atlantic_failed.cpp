class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& result, int r, int c,
             unordered_set<vector<int>>& visited, int start_r, int start_c) {
        // if we have already visited no point in visiting again:
        if (visited.contains({r, c})) {
            return;
        }
        visited.insert({r, c});
        // base case is if we hit an atlantic cell
        if ((r == heights.size() - 1) || (c == heights[0].size())) {  
            result.push_back({r, c});
            if (start_r != r && start_c != c) {
                result.push_back({start_r, start_c});
            }
            visited.erase({r, c});
            return;
        }
        // then we will explore all of them we can go to next
        static constexpr int dr[] = {-1, 1, 0, 0};
        static constexpr int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int cr = r + dr[i];
            int cc = c + dc[i];
            if (cr >= 0 && cc >= 0 && cr < heights.size() && cc < heights[0].size() &&
                heights[cr][cc] >= heights[r][c]) {
                visited.insert({cr, cc});
                dfs(heights, result, cr, cc, visited, start_r, start_c);
            }
        }
        visited.erase({r, c});
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        // we also don't want any cycles so we should have visited list:
        unordered_set<vector<int>> visited;
        // Go through edges and see if a number is bigger or equal we keep going up
        // then we will only need to check top left edges as the only stuff from atlantic
        // we care about are the ones that go into pacific
        // we will go through left colum first:
        for (int i = 0; i < result.size(); ++i) {
            dfs(heights, result, i, 0, visited, i, 0);
        }
        // we will go through top row next:
        for (int i = 0; i < result[0].size(); ++i) {
            dfs(heights, result, 0, i, visited, i, 0);
        }
        return result;
    }
};

