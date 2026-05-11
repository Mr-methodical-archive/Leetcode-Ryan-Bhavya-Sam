class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int i = 0; i < nums.size(); ++i) {
            // two choices:
            if (sub.empty() || nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                // it is less than so we need to find the element to binary search replace with it
                int lo = 0;
                int hi = sub.size() - 1;
                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;
                    if (sub[mid] < nums[i]) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                sub[lo] = nums[i];
            }
        }
        return sub.size();
    }
};
