class Solution {
public:
    // next step
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            } else {
                ++count;
            }
        }
        vector<int> retval;
        retval.reserve(count);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                retval.push_back(i + 1);
            }
        }
        return retval;
    }
};
