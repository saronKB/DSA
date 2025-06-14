class Solution {
public:
    bool isConnected(vector<vector<int>>& directions, int prevStreetType, int targetDy, int targetDx) {
        int directionIndex = prevStreetType * 2;
        for (int i = 0; i < 2; ++i) {
            int deltaY = directions[directionIndex + i][0];
            int deltaX = directions[directionIndex + i][1];
            if (deltaY == targetDy && deltaX == targetDx) {
                return true;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        vector<vector<int>> directions = {
            {0, -1}, {0, 1},
            {-1, 0}, {1, 0}, 
            {0, -1}, {1, 0}, 
            {0, 1}, {1, 0},  
            {0, -1}, {-1, 0},
            {0, 1}, {-1, 0}  
        };

        queue<int> bfsQueue;
        unordered_set<int> visitedCells;
        bfsQueue.push(0);
        visitedCells.insert(0);

        while (!bfsQueue.empty()) {
            int cellIndex = bfsQueue.front();
            bfsQueue.pop();
            int row = cellIndex / numCols;
            int col = cellIndex % numCols;

            if (row == numRows - 1 && col == numCols - 1) {
                return true;
            }

            int currentStreetType = grid[row][col] - 1;
            int directionIndex = currentStreetType * 2;

            for (int i = 0; i < 2; ++i) {
                int newRow = row + directions[directionIndex + i][0];
                int newCol = col + directions[directionIndex + i][1];
                int newCellIndex = newRow * numCols + newCol;

                if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols &&
                    !visitedCells.count(newCellIndex) &&
                    isConnected(directions, grid[newRow][newCol] - 1,
                                -directions[directionIndex + i][0],
                                -directions[directionIndex + i][1])) {
                    visitedCells.insert(newCellIndex);
                    bfsQueue.push(newCellIndex);
                }
            }
        }

        return false;
    }
};