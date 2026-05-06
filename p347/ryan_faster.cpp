class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto& [key, value] : freq) {
            min_heap.push({value, key});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            auto& [key, value] = min_heap.top();
            result.push_back(value);
            min_heap.pop();
        }
        return result;
    }
};
