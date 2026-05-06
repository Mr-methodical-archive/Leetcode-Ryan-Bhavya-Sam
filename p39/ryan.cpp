class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& result, vector<int>& curr, int sum, int target, int start) {
        // how do we make sure it is not already in the set???
        // maybe we need to 
        if (sum == target) {
            result.push_back(curr);
            return;
        } else if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            backtrack(candidates, result, curr, sum + candidates[i], target, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(candidates, result, curr, 0, target, 0);
        return result;
    }
};
