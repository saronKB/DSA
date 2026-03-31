class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        expectedSum= n*(n+1)//2
        currentSum=sum(nums)
        return expectedSum-currentSum