class Solution {
public:
    bool is_palindrome(string& s, int left, int right) {
        // "baa" 1 2
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>>& result, vector<string>& curr, string& s, int start) {
        if (start == s.length()) {
            // maybe for the loop have another index and we go across it and expand it ['a', 'aa', 'aab']
            //  and check if it is a palindrome
            result.push_back(curr);
            return;
        }
        for (int end = start; end <= s.length(); ++end) {
            if (is_palindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                backtrack(result, curr, s, end + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // step 1 should be to build it
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(result, curr, s, 0);
        return result;
    }
};
