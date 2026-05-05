class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // similar level_size thing
        vector<vector<int>> retval;
        retval.push_back({});
        for (int i = 0; i < nums.size(); ++i) {
            int level_size = retval.size();
            for (int j = 0; j < level_size; ++j) {
                // we want to add nums[i] onto every element in it
                vector<int> curr(retval[j]);
                curr.push_back(nums[i]);
                retval.push_back(curr);
            }
        }
        return retval;
    }
};
