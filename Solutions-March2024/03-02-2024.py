class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        res = [0]*len(nums)
        for i in range(len(nums)):
            res[i] = nums[i] *nums[i]
        res.sort()
        return res
