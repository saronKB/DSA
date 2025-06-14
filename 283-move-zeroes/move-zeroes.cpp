#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;

        // Move non-zero values forward
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }

        // Fill the rest with zeroes
        while (pos < n) {
            nums[pos++] = 0;
        }

        // Optional: print result
        cout << "Result after shifting zeros to the right: ";
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};
