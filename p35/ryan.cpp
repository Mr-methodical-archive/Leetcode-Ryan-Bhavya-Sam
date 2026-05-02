class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // works because every element less lo is guaranteed to be less than
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
