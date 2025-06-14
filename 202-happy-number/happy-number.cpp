#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum=sum + digit * digit;
                n=n / 10;
            }
            n = sum;
        }
        
        return n == 1;
    }
};

