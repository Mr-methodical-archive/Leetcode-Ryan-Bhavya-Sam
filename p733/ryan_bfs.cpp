class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int og_color = image[sr][sc];
        image[sr][sc] = color;

        while (!empty(q)) {
            auto [x, y] = q.front();
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for (size_t i = 0; i < 4; ++i) {
                int nr = x + dr[i];
                int nc = y + dc[i];
                if (nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size() && image[nr][nc] == og_color) {
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }
            q.pop();
        }
        return image;
    }
};
