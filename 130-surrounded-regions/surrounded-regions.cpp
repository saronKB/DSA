class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if (height == 0) return;
        int width = board[0].size();
        vector<vector<bool>> save(height, vector<bool>(width, false));
        function<void(int, int)> find = [&](int row, int col) {
            if (row < 0 || row >= height || col < 0 || col >= width || board[row][col] != 'O' || save[row][col]) return;
            save[row][col] = true;
            find(row+1, col);
            find(row-1, col);
            find(row, col+1);
            find(row, col-1);
        };
        for (int row = 0; row < height; row++) {
            if (board[row][0] == 'O') find(row, 0);
            if (board[row][width-1] == 'O') find(row, width-1);
        }
        for (int col = 0; col < width; col++) {
            if (board[0][col] == 'O') find(0, col);
            if (board[height-1][col] == 'O') find(height-1, col);
        }
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                if (board[row][col] == 'O' && !save[row][col]) board[row][col] = 'X';
            }
        }
    }
};