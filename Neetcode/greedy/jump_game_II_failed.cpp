class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int idx = 0;
        while (true) {
            // idea is we will go with whichever one can get us biggest index
            int max_idx = idx + 1; // we will always have to least go to the next one
            int options = nums[idx];
            if (idx + options >= nums.size()) {
                return count; 
            }
            for (int j = 1; j < options; ++j) {
                max_idx = max({max_idx, idx + j + nums[idx + j]});
            }
            idx = max_idx;
            count++;
        }
        return count; // we should never reach this
    }
};

