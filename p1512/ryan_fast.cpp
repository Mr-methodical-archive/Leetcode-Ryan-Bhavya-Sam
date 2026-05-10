class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // now let's do faster in O(n) witth a hash map
        unordered_map<int, int> freq; // val: freq
        for (int num: nums) freq[num]++;
        int ans = 0;
        for (auto& [_, f] : freq) {
            ans += (f * (f - 1)) / 2;
        }
        return ans;
    }
};
