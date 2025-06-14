class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int height = board.size();
        if (height == 0) return board;
        int width = board[0].size();
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        function<void(int, int)> show = [&](int row, int col) {
            if (row < 0 || row >= height || col < 0 || col >= width || board[row][col] != 'E') return;
            int mines = 0;
            vector<unordered_map<string, int>> moves = {
                {{"dr", -1}, {"dc", -1}}, {{"dr", -1}, {"dc", 0}}, {{"dr", -1}, {"dc", 1}},
                {{"dr", 0}, {"dc", -1}}, {{"dr", 0}, {"dc", 1}},
                {{"dr", 1}, {"dc", -1}}, {{"dr", 1}, {"dc", 0}}, {{"dr", 1}, {"dc", 1}}
            };
            for (auto move : moves) {
                int newRow = row + move["dr"], newCol = col + move["dc"];
                if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && board[newRow][newCol] == 'M') {
                    mines++;
                }
            }
            if (mines > 0) {
                board[row][col] = '0' + mines;
                return;
            }
            board[row][col] = 'B';
            for (auto move : moves) {
                show(row + move["dr"], col + move["dc"]);
            }
        };
        show(r, c);
        return board;
    }
};