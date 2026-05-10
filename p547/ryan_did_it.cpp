class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int city, vector<bool>& visited) {
        visited[city] = true;
        for (int other = 0; other < isConnected[0].size(); ++other) {
            if (isConnected[city][other] && !visited[other]) {
                dfs(isConnected, other, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool> visited(isConnected.size(), false);
        // we need to go through each city:
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                ++count;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};
