class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int l = nums.size() / 2;
        int best = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                count = 1;
                best = nums[i];
            } else if (nums[i] != best) {
                --count;
            } else {
                ++count;
            }
        }
        return best;
    }
};
