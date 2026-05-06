class Solution {
public:
    // next step
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        vector<int> retval;
        for (int i = 1; i <= nums.size(); ++i) {
            if (seen.count(i) == 0) {
                retval.push_back(i);
            }
        }
        return retval;
    }
};
