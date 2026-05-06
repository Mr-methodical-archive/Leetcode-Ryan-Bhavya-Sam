class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // we could insert into a priority queue and that would be nlogn
        // We need a min_heap, so smallest elements at the top;
        // we should do a max heap instead actually

        priority_queue<int, vector<int>, less<int>> max_heap(nums.begin(), nums.end()); // this is O(n)
        // we might need to do our memory different later
        for (int i = 0; i < k - 1; ++i) {
            max_heap.pop();
        }
        return max_heap.top();
    }
};
