class Solution {
public:
    int minDistance(string word1, string word2) {
        // let's set up the usual pattern we use for longest common subsequence
        int n = word1.size();
        int m = word2.size();
        // we need to convert word1 to word2
        // maybe we go through once and then figure out what we have and then we can use our delete and insert to see what we need to add and stuff
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // left side is word1 and top is word 2, so the first column is empty string for word1 so it should just be what we would need to insert
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        // the same thing would happen with the first row
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // nothing we good, no changes
                } else {
                    // we need to decide whether to delete, insert, or replace
                    // we want the min of all our options 
                    // 3 options, we could delete it, insert it, or replace it
                    // 1 + dp[i - 1][j - 1] is for replacing it
                    // then we could go one up and one back and that would be like deleting which ever one we wanted
                    dp[i][j] = min({1 + dp[i - 1][j - 1], 1 + dp[i - 1][j], 1 + dp[i][j - 1]});
                }
            }
        }
        return dp[n][m];
    }
};
