#include <iostream>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, split = 0;
        for (char c : s) {
            if (c == 'L'){
                split++;
            } else {
                split--;
            }if (split == 0){
                count++;} 
        }
        return count;
    }
};

