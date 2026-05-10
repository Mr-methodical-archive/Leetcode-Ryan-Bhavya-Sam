class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return;
        int og_color = image[sr][sc];
        image[sr][sc] = color;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int cr = sr + dr[i];
            int cc = sc + dc[i];
            // could be problematic because O(n)
            if (cr >= 0 && cc >= 0 && cr < image.size() && cc < image[0].size() && image[cr][cc] == og_color) {
                dfs(image, cr, cc, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int, int>> visited;
        dfs(image, sr, sc, color);
        return image;
    }
};
