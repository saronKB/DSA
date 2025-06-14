class Solution {
public:
    int n;
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        q.push(1);  
        vector<bool> visited(n * n + 1, false);
        visited[1] = true;
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int curr = q.front(); q.pop();
                if (curr == n * n) return steps;
                for (int next = curr + 1; next <= min(curr + 6, n * n); ++next) {
                    auto [r, c] = getPosition(next);
                    int destination = (board[r][c] == -1) ? next : board[r][c];
                    if (!visited[destination]) {
                        visited[destination] = true;
                        q.push(destination);
                    }
                }
            }
            ++steps;
        }

        return -1;
    }

    pair<int, int> getPosition(int num) {
        int row = (num - 1) / n;
        int col = (num - 1) % n;
        if (row % 2 == 1) col = n - 1 - col;
        return {n - 1 - row, col};
    }
};