class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return nums.size();
        unordered_set<int> elements(nums.begin(), nums.end());
        int curr_count = 0;
        int best_count = 0;
        for (int x : elements) {
            if (elements.count(x - 1) == 0) {
                // then we have a start of sequence
                // so we iterate
                int trav = x;
                while (elements.count(trav) == 1) {
                    ++curr_count;
                    ++trav;
                }
                best_count = max(best_count, curr_count);
                curr_count = 0;
            } 
        }
        return best_count;
    }
};
