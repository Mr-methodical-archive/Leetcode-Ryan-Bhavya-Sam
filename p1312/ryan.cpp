class Solution {
public:
    int minInsertions(string s) {
        // How much is the same as the reverse, so we see that and depending on that we copy it that way:
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s[n - j]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // the question is how much of it matched up
        // oh this actually gave us the palindrome size not having to be continuous
        return n - dp[n][n];
        // idea is that if odd then it will go integer division down to round down, but if even then it should be that many items actually
        // to create the mirror you just need one insertion
        
    }
};
