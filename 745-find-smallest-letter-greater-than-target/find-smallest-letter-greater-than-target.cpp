class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int small = 0;
        int big = n - 1;
        while (small <= big) {
            int mid = small + (big - small) / 2;
            if (letters[mid] <= target) {
                small = mid + 1;
            } else {
                big = mid - 1;
            }
        }
        return letters[small % n];
    }
};