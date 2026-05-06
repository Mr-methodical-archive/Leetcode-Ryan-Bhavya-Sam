class Solution {
public:
    void backtrack(vector<int>& current, vector<vector<int>>& result, int k, int iterator, int n) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        for (int i = iterator; i <= n; ++i) {
            current.push_back(i);
            backtrack(current, result, k, i + 1, n);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> result;
        backtrack(current, result, k, 1, n);
        return result;
    }
};
