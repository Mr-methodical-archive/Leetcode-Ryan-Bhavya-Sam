class Solution {
public:
    void backtrack(vector<string>& result, string& curr, string& digits, unordered_map<char, string>& order, int idx) {
        if (idx == digits.length()) {
            result.push_back(curr);
            return;
        }
        for (char c : order[digits[idx]]) {
            curr.push_back(c);
            backtrack(result, curr, digits, order, idx + 1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> order;
        order['2'] = "abc";
        order['3'] = "def";
        order['4'] = "ghi";
        order['5'] = "jkl";
        order['6'] = "mno";
        order['7'] = "pqrs";
        order['8'] = "tuv";
        order['9'] = "wxyz";
        vector<string> result;
        string curr;
        backtrack(result, curr, digits, order, 0);
        return result;
    }
};
