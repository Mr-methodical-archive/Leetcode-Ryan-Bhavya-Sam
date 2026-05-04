class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // the edges are always only 1 way to get since we can only move right and down:
                if (i == 0 || j == 0) {
                    dp[j] = 1;
                } else {
                    // we need to add number of paths above and too left because both could have got us there:
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};
