#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) return true;

        int beginning = 0;
        int end = s.size() - 1;

        while (beginning < end) {
            while (beginning < end && !isalnum(s[beginning])) beginning++;
            while (beginning < end && !isalnum(s[end])) end--;
            
            if (tolower(s[beginning]) != tolower(s[end])) return false;

            beginning++;
            end--;
        }

        return true;
    }
};
