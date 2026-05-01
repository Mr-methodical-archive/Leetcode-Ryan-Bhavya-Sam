class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> words;
        for (const string& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            words[sorted_str].push_back(str);
        }
        vector<vector<string>> retval;
        for (auto& [_, value] : words) {
            retval.push_back(move(value));
        }
        return retval;
    }
};
