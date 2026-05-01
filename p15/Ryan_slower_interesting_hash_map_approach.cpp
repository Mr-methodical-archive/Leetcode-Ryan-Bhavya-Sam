class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> retval;
        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            // assume nums[i] is in it we need our next two numbers to be -nums[i]
            unordered_set<int> seen;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (seen.contains(-1 * (nums[i] + nums[j]))) {
                    retval.push_back({nums[i], -1 * (nums[i] + nums[j]), nums[j]});
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                } else {
                    seen.insert(nums[j]);
                }
            } 
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return retval;
    }
};
