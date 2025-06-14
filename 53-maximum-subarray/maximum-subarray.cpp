class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==0)
        return 0;
        int maxOfSums=nums[0];
        int currentSum=nums[0];
        for (int i=1;i<nums.size();++i){
            int n=nums[i];
            currentSum=max(currentSum+ n,n);
            maxOfSums=max(maxOfSums,currentSum);
        }
        return maxOfSums;
        
    }
};