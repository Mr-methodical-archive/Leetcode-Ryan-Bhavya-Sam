class Solution {
public:
    void sortColors(vector<int>& nums) { 
        int left_index = 0;
        int right_index = nums.size() - 1;
        for (int i = 0; i <= right_index; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left_index++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right_index--]);
                --i;
            }
        }
    }
};
