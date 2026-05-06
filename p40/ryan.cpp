class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& curr, int target, int sum, int start) {
        if (sum == target) {
            result.push_back(curr);
            return;
        } else if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            backtrack(result, candidates, curr, target, sum + candidates[i], i + 1);
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) ++i;
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(result, candidates, curr, target, 0, 0);
        return result;
    }
};
