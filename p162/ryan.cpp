class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else {
                // else the next one to the right is actually smaller so mid is still possible
                hi = mid;
            }
        }
        // so then we end knowing lo must be greater than the element before it
        // and we know we know the element after it must smaller because we always move hi when 
        // and then we also know that hi must now be equal to lo
        return lo;
    }
};
