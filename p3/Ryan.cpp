class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // maybe use hash table
        unordered_map<char, int> us; // where int is index
        int left = 0;
        int max_sum = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (us.contains(s[right]) && us[s[right]] >= left) {
                left = us[s[right]] + 1;
            }
            us[s[right]] = right;
            max_sum = max(max_sum, right - left + 1);
        }
        return max_sum;
    }
};
