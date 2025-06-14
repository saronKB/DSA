class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, int& count) {
        visited[node] = true;
        count++;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, neighbor, visited, count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    long long x2 = bombs[j][0], y2 = bombs[j][1];
                    long long dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                    if (dist <= r1 * r1) {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int count = 0;
            dfs(graph, i, visited, count);
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};