class Solution {
public:
    int find_bound(vector<int>& nums, int target, bool left_most) {
        int lo = 0;
        int hi = nums.size() - 1;
        int index = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target && left_most) {
                index = mid;
                hi = mid - 1;
            } else if (nums[mid] == target && !left_most) {
                index = mid;
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {find_bound(nums, target, true), find_bound(nums, target, false)};
    }
};
