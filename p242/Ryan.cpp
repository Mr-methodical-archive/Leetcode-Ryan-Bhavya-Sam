class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> us;
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); ++i) {
            us[s[i]]++;
            us[t[i]]--;
        }
        for (auto [key, val] : us) {
            if (val != 0) return false;
        }
        return true;
    }
};
