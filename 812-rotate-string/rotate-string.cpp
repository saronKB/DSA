class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size())
            return false;
        if (A.empty())
            return true;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            bool isShift = true;
            while (i < n && A[0] != B[i])
                ++i;
            for (int j = 0; j < n && isShift; ++j)
                if (A[j] != B[(i + j) % n])
                    isShift = false;
            if (isShift)
                return true;
        }
        return false;
    }
};