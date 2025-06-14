#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string outcome = "";
        int left = 0;
        
        while (i >= 0 || j >= 0 || left == 1) {
            if (i >= 0) {
                left += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                left += b[j] - '0';
                j--;
            }
            outcome += (left % 2) + '0';
            left /= 2;
        }
        
        reverse(outcome.begin(), outcome.end());
        return outcome;
    }
};

