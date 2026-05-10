class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& dp, vector<bool>& visited, vector<bool>& seen, int course) {
        // there's a cycle so return false:
        if (seen[course]) return false;
        // we might already know this one is fine:
        if (visited[course]) return true;
        seen[course] = true;
        // we should check through all the prereqs for it:
        for (int curr_course : dp[course]) {
            if (!dfs(dp, visited, seen, curr_course)) return false;
        }
        visited[course] = true;
        seen[course] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // maybe all the courses a certain course depends on
        unordered_map<int, vector<int>> dp;
        for (auto& vec : prerequisites) {
            dp[vec[1]].push_back(vec[0]);
            // because then we will have to see what all the requirments for the prereqs are
        }
        // if there is a cycle then we should return false
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            vector<bool> seen(numCourses, false);
            if (!dfs(dp, visited, seen, i)) return false;
        }
        return true;
    }
};
