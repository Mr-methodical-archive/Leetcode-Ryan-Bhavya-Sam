class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, unordered_set<int>& visited, vector<int>& current) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited.count(nums[i]) != 0) continue;
            visited.insert(nums[i]);
            current.push_back(nums[i]);
            backtrack(nums, result, visited, current);
            current.pop_back();
            visited.erase(nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        unordered_set<int> visited;
        backtrack(nums, result, visited, current);
        return result;
    }
};
