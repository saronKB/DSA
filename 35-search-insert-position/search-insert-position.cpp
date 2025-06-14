class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;  
        int l = 0, r = n, mid;
        while (l < r) {
            mid = l + (r - l) / 2; 
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;  
        }
        return l;
    }
};