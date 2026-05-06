class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>> max_heap;
        for (auto& [key, value] : freq) {
            // max_heap will put max to the bottom, so we actually need a min heap where the max is at the top
            max_heap.push({value, key});
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            auto& [key, value] = max_heap.top();
            result.push_back(value);
            max_heap.pop();
        }
        return result;
    }
};
