class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we want nums1 to be smaller or equal to
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int lo = 0;
        int hi = m;
        int half = (m + n + 1) / 2; // so left will always have more
        while (lo <= hi) { // how do I know when to do lo < hi and lo <= hi
            int i = lo + (hi - lo) / 2; // the partion ccut
            int j = half - i;
            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i]; // why do we need this when would it ever be m isn't it always midpoint
            // now thinking about it more, I guess it could because lo could be equal to hi
            int right2 =  (j == n) ? INT_MAX : nums2[j];
            // we need to see if it is actually the right partition
            if (left1 > right2) {
                hi = i - 1;
            } else if (left2 > right1) {
                lo = i + 1;
            } else {
                // we found the right partition
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
        }
        return -1; // will never happen
    }
};
