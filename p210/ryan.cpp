class Solution {
public:
    bool dfs(vector<vector<int>>& dp, vector<bool>& visited, vector<bool>& in_path, int course, vector<int>& result) {
        if (in_path[course]) return false;
        if (visited[course]) return true;
        in_path[course] = true;
        for (int curr_course : dp[course]) {
            if (!dfs(dp, visited, in_path, curr_course, result)) return false;
        }
        result.push_back(course);
        // we should only be pushing back if we havent' seen it and that is what we kind of do I think
        visited[course] = true;
        in_path[course] = false;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // we need to know what is a good course, maybe we assume to go with one, or we like fill up graph
        // well we should try to detect cycles again as well, so let's set that up once more, but use vector this time instead
        // the columns will represent the course and then the rows will represent which is a required prereq
        vector<vector<int>> dp(numCourses);
        for (auto& prereq : prerequisites) {
            dp[prereq[1]].push_back(prereq[0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> in_path(numCourses, false);
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(dp, visited, in_path, i, result)) return {};
        }
        // result is currently in order of courses that are the most important for us to take since we are going all
        // the way down and then pushing them on.
        reverse(result.begin(), result.end());
        return result;
    }
};
