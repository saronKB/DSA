class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
         int n = grid.size();
        queue<pair<int, int>> landQueue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    landQueue.push({i, j});
                }
            }
        }

        if (landQueue.empty() || landQueue.size() == n * n) return -1;

        int maxDist = -1;
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!landQueue.empty()) {
            int sz = landQueue.size();
            maxDist++; 
            for (int i = 0; i < sz; i++) {
                auto [row, col] = landQueue.front();
                landQueue.pop();

                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow >= 0 && newRow < n &&
                        newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 0) {
                        grid[newRow][newCol] = 1;
                        landQueue.push({newRow, newCol});
                    }
                }
            }
        }

        return maxDist;
    }
};
