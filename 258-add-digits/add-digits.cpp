class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int summation = 0;
            while (num > 0) {
                summation += num % 10;
                num /= 10;
            }
            num = summation;
        }
        return num;
    }
};
