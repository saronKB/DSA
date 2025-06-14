class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> outcome(n, 0);
        for (int i = 0; i < n - 1; i += 2) {
            outcome[i] = (i + 1);
            outcome[i + 1] = -(i + 1);
        }
        return outcome;
    }
};