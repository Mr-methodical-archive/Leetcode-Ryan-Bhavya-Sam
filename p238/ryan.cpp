class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // idea we multiply by left first and then we multiply by right
        // so left is going to be the product from the left side
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        vector<int> ans(nums.size());
        left[0] = 1;
        right[nums.size() - 1] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        } // now [1, 1, 2, 6];
        for (int i = nums.size() - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        } // now [24, 12, 4, 1]
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
