class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        vector<vector<int>> buckets(nums.size() + 1); // we have indexes going up nums.size() because 
        // frequency can go up that much
        for (auto& [key, value] : freq) {
            buckets[value].push_back(key);
        }
        vector<int> result;
        for (int i = nums.size(); i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
            }
        }
        return result;
    }
};
