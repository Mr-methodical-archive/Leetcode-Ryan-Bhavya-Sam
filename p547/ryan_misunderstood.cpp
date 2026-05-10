class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, int j) { // it will say if we have already visited it
        isConnected[i][j] = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            int cr = i + dr[k];
            int cc = j + dc[k];
            if (cr >= 0 && cc >= 0 && cr < isConnected.size() && cc < isConnected[0].size() && isConnected[cr][cc] != 0) {
                dfs(isConnected, cr, cc);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // we need to find number of islands
        // it is adjacent how they are connected
        // maybe we need a visited list and we go through every single one
        // I can just mark them as visited by giving them a zero
        int count = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected[0].size(); ++j) {
                if (isConnected[i][j] == 1) {
                    count++;
                    dfs(isConnected, i, j);
                }
                
            }
        }
        return count;
    }
};
