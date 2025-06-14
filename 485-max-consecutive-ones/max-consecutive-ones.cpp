#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int maxNum = 0; 
        int currentNum = 0;

        for (int num : nums) {
            if (num == 1) {
                currentNum++;  
                maxNum = std::max(maxNum, currentNum);  
            } else {
                currentNum = 0;  
            }
        }

        return maxNum;
    }
};


