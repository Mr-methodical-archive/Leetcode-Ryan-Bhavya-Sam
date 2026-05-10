class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>>& memo) {
        if (nums1.size() == n || nums2.size() == m) return 0;
        if (memo[n][m] != -1) return memo[n][m];
        if (nums1[n] == nums2[m]) {
            memo[n][m] = 1 + helper(nums1, nums2, n + 1, m + 1, memo);
        } else {
            // they don't match
            memo[n][m] = 0;
        }
        // we need to return the best we have seen so far:
        return memo[n][m];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        helper(nums1, nums2, 0, 0, memo);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, helper(nums1, nums2, i, j, memo));
            }
        }
        return ans;
    }
};
