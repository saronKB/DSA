#include <vector>

class Solution {
public:
    std::vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> result;
        for (int i= left; i <= right; ++i) {
            int temp = i;
            bool isCorrect = true;
            
            while (temp > 0) {
                int digit = temp % 10;
                if (digit == 0 || i % digit != 0) {
                    isCorrect = false;
                    break;
                }
                temp /= 10;
            }
            
            if (isCorrect) result.push_back(i);
        }
        return result;
    }
};
