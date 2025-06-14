class Solution {
public:
    int maximum69Number(int num) {
        vector<int> digits;
        int x = num;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 6) {
                digits[i] = 9;
                break;
            }
        }
        int outcome = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            outcome = outcome * 10 + digits[i];
        }

        return outcome;
    }
};
