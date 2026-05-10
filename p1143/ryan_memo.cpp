class Solution {
public:
    int helper(string& text1, string& text2, int idx1, int idx2, vector<vector<int>>& memo) {
        if (text1.length() == idx1 || text2.length() == idx2) return 0;
        if (memo[idx1][idx2] != - 1) return memo[idx1][idx2];
        if (text1[idx1] == text2[idx2]) memo[idx1][idx2] = 1 + helper(text1, text2, idx1 + 1, idx2 + 1, memo);
        else memo[idx1][idx2] = max(helper(text1, text2, idx1 + 1, idx2, memo), helper(text1, text2, idx1, idx2 + 1, memo));
        return memo[idx1][idx2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return helper(text1, text2, 0, 0, memo);
    }
};
