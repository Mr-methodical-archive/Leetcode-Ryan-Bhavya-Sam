class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // the edges are always only 1 way to get since we can only move right and down:
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    // we need to add number of paths above and too left because both could have got us there:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
