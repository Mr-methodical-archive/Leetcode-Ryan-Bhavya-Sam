class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> words;
        for (const string& str : strs) {
            array<int, 26> word = {};
            for (char c : str) {
                word[c - 'a']++;
            }
            string key(word.begin(), word.end());
            words[key].push_back(str);
        }
        vector<vector<string>> retval;
        for (auto& [_, value] : words) {
            retval.push_back(move(value));
        }
        return retval;
    }
};
