class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i; j > 0; --j) {
                if (nums[j - 1] < nums[i]) {
                    dp[i] = max(dp[i], dp[j - 1] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
