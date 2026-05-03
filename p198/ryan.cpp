class Solution {
public:
    int rob(vector<int>& nums) {
        int down_1 = 0;
        int down_2 = 0;
        int new_max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            new_max = max(down_1, down_2 + nums[i]);
            down_2 = down_1;
            down_1 = new_max;
        }
        return new_max;
    }
};
