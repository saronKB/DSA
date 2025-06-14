class Solution {
public:
    int arrangeCoins(int n) {
        long low = 0, high = n;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if ((mid + 1) * mid / 2 > n) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low - 1;
    }
};