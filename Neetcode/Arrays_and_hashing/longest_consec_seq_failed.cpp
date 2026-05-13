class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sorting it would be easiest but they said O(n)
        // we could do a hash map and then just add 1 to it
        unordered_map<int, int> consec;
        for (int i = 0; i < nums.size(); ++i) {
            // don't change anything we already have that value
            if (consec.contains(nums[i])) continue;
            // the one thing we have to be careful of is that we do
            // need to edit the edges like the one less and one more
            int left = 0;
            int right = 0;
            if (consec.contains(nums[i] - 1)) left = consec[nums[i] - 1];
            if (consec.contains(nums[i] + 1)) right = consec[nums[i] + 1];
            int new_val = max(1 + left, 1 + right);
            consec[nums[i]] = new_val;
            // since they are close by we also have to update them with the value
            if (consec.contains(nums[i] - 1)) consec[nums[i] - 1] = new_val;
            if (consec.contains(nums[i] + 1)) consec[nums[i] + 1] = new_val;
        }
        int result = 1;
        for (const auto& [key, value] : consec) {
            result = max(result, value);
        }
        return result;
    }
};

