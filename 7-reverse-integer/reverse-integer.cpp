class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        int max = INT_MAX / 10;
        int min = INT_MIN / 10;

        while (x != 0) {
            int digit = x % 10;
            if (reversed > max || reversed < min) {
                return 0;
            }

            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return reversed;
    }
};
