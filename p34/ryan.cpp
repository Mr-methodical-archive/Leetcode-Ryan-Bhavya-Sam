class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // we need to find the range:
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                // we need to find left and find right:
                int lo_lp = lo;
                int hi_lp = mid - 1;
                int left_index = mid;
                while (lo_lp <= hi_lp) {
                    int mid_lp = lo_lp + (hi_lp - lo_lp) / 2;
                    if (nums[mid_lp] == target) {
                        left_index = mid_lp;
                        hi_lp = mid_lp - 1;
                    } else if (nums[mid_lp] < target) {
                        lo_lp = mid_lp + 1;
                    } else {
                        hi_lp = mid_lp - 1;
                    }
                }
                int lo_rp = mid + 1;
                int hi_rp = hi;
                int right_index = mid;
                while (lo_rp <= hi_rp) {
                    int mid_rp = lo_rp + (hi_rp - lo_rp) / 2;
                    if (nums[mid_rp] == target) {
                        right_index = mid_rp;
                        lo_rp = mid_rp + 1;
                    } else if (nums[mid_rp] < target) {
                        lo_rp = mid_rp + 1;
                    } else {
                        hi_rp = mid_rp - 1;
                    }
                }
                return {left_index, right_index};
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return {-1, -1};
    }
};
