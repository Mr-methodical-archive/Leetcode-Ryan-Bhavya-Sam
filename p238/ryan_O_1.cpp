class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // idea we multiply by left first and then we multiply by right
        // so left is going to be the product from the left side
        // maybe we can do it one for loop actually
        // what are all the things on the left 
        vector<int> ans(nums.size());
        ans[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        } // now [1, 1, 2, 6];
        int mult = 1;
        for (int j = nums.size() - 1; j >= 0; --j) {
            ans[j] = mult * ans[j];
            mult *= nums[j];
        } // [,8,6]
        return ans;
    }
};
