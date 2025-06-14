class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> character(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)A[i].size(); ++j) {
                ++character[i][A[i][j] - 'a'];
            }
        }
        vector<string> outcome;
        for (int i = 0; i < 26; ++i) {
            int m = INT_MAX;
            for (int j = 0; j < n; ++j) {
                m = min(m, character[j][i]);
            }
            for (; m > 0; --m) {
                outcome.push_back(string(1, 'a' + i));
            }
        }
        return outcome;
    }
};