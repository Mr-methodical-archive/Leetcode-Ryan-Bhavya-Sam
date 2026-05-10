class Solution {
public:
    int minDistance(string word1, string word2) {
        // we could just find the size of the longest common subseq, and then subtract that from both words and that is the nubmer fo deletions we need
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n + m - (2 * dp[n][m]);
    }
};
