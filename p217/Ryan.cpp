class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); ++i) {
            if (us.count(nums[i]) == 1) {
                return true;
            }
            us.insert(nums[i]);
        }
        return false;
    }
};
