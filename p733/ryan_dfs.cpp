class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image; // base case
        int og_color = image[sr][sc];
        image[sr][sc] = color;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if (nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size() && 
                image[nr][nc] == og_color) {
                floodFill(image, nr, nc, color);
            }
        }
        return image;
    }
};
