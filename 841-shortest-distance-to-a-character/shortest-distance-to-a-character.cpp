class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int x = S.size();
        vector<int> target, outcome(x, INT_MAX);
        for (int i = 0; i < x; ++i) {
            if (S[i] == C) {
                target.push_back(i);
            }
        }
        for (int j = 0; j < target.front(); ++j)
            outcome[j] = target.front() - j;
        for (int j = target.back(); j < x; ++j)
            outcome[j] = j - target.back();
        for (int i = 1; i < target.size(); ++i) {
            for (int j = target[i - 1]; j <= target[i]; ++j) {
                outcome[j] = min(j - target[i - 1], target[i] - j);
            }
        }
        return outcome;
    }
};