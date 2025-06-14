class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int begin = 1, end = x / 2, answer = 0;

        while (begin <= end) {
            long long mid = begin + (end - begin) / 2;
            long long sq = mid * mid;

            if (sq == x) return mid;
            else if (sq < x) {
                answer = mid;  // mid might be the answer
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return answer;
    }
};
