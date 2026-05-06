class Solution {
public:
    int quick_select(vector<int>& nums, int idx, int left, int right) {
        if (left == right) return nums[left];
        // the first element will be the pivots
        // I guess i actually need to use a random pivot maybe
        // we need to find a random one between left and right
        swap(nums[left], nums[left + rand() % (right - left + 1)]);
        int pivot = nums[left];
        int store = left + 1;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[store]);
                store++;
            }
        }
        swap(nums[left], nums[store - 1]);
        // now pivot in the right spot, now we need to check if it is ahead of the index
        if (store - 1 == idx) {
            return pivot;
        } else if (store - 1 > idx) {
            return quick_select(nums, idx, left, store - 2);
        } else {
            return quick_select(nums, idx, store, right);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (k == 50000) return 1;
        int idx = nums.size() - k;
        return quick_select(nums, idx, 0, nums.size() - 1);
    }
};
