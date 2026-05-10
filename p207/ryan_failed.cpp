class Solution {
public:
    void helper(unordered_map<int, vector<int>>& dp, unordered_set<int>& seen, int curr_course) {
        if (seen.contains(curr_course)) return;
        if (!dp.contains(curr_course)) {
            seen.insert(curr_course);
            return;
        }
        for (int course : dp[curr_course]) {
            helper(dp, seen, course);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // we could create a hash map to see what we unlock when we get a course int, vector
        // we have met our goal when our number of unique courses we can take is possible
        unordered_map<int, vector<int>> dp;
        for (auto& [key, value] : prerequisites) {
            dp[key].push_back(value);
        }
        // Let's go with DFS path
        // we need some way to know if we have counted them yet
        unordered_set<int> seen;
        helper(dp, seen, curr);
        for (auto& [key, value] : prerequisites) {
            helper(dp, seen, int value);
        }
        return seen.size() == numCourses;
    }
};
