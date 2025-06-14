class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int numOfSteps = -1;
        queue<vector<int>> PossiblePaths;
        int steps = 0;

        entrance.push_back(steps); 
        PossiblePaths.push(entrance);
        maze[entrance[0]][entrance[1]] = '+'; 

        while (!PossiblePaths.empty()) {
            vector<int> Element = PossiblePaths.front();
            int row = Element[0];
            int col = Element[1];
            steps = Element[2];

            vector<vector<int>> directions = {
                { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
            };

            for (auto dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < maze.size() && newCol >= 0 && newCol < maze[0].size() && maze[newRow][newCol] == '.') {
                    
                    if (newRow == 0 || newRow == maze.size() - 1 || newCol == 0 || newCol == maze[0].size() - 1) {
                        return steps + 1;
                    }

                    maze[newRow][newCol] = '+'; 
                    vector<int> newElement = { newRow, newCol, steps + 1 };
                    PossiblePaths.push(newElement);
                }
            }

            PossiblePaths.pop();
        }

        return numOfSteps; 
    }
};

