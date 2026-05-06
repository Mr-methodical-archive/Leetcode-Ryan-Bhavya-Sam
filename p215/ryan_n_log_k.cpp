class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // we could also add it gradually, maybe we could keep track of largest
        // we could push on 
        // we could do a min heap and we keep taking off the smallest maybe
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < nums.size(); ++i) {
            min_heap.push(nums[i]);
            // we should take off
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};
