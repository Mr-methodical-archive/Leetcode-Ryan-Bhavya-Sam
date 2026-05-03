class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int half = (m + n + 1) / 2; // make sure more ends up on left if extra 1; also it is count not index
        int lo = 0;
        int hi = m; // again these are counts
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2; // elements to take from nums1
            int j = half - i; // number of elements to take from nums2
            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];
            int right2 = (j == n) ? INT_MAX : nums2[j];
            if (left1 > right2) {
                hi = i - 1;
            } else if (left2 > right1) {
                lo = i + 1;
            } else { // the partition is good
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
        }
        return -1; // not possible to get here though
    }
};
