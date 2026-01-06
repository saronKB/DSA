class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        newArray=[]
        summation=0
        for i in nums:
            summation=summation +i
            newArray.append(summation)
        return newArray
        