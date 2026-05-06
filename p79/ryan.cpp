class Solution {
public:
    void backtrack(vector<vector<char>>& board, string& word, int idx, bool& exist, int row, int col) {
        if (exist) return;
        if (idx == word.length()) {
            exist = true;
            return;
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            // 3 conditions to go down it (valid index, not visited yet, and next letter of the word)
            if (nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() && board[nr][nc] == word[idx]) {
                char temp = board[nr][nc];
                board[nr][nc] = '#';
                backtrack(board, word, idx + 1, exist, nr, nc);
                board[nr][nc] = temp;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        // we might need a vector<pair<int, int>>
        // track with index
        bool existence = false;
        for (int i = 0; i < board.size(); ++i) {
            if (existence) break;
            for (int j = 0; j < board[0].size(); ++j) {
                if (existence) break;
                if (board[i][j] == word[0]) {
                    char temp = board[i][j];
                    board[i][j] = '#';
                    backtrack(board, word, 1, existence, i, j);
                    board[i][j] = temp;
                }
            }
        }
        return existence;
    }
};
