class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        res = nums.copy()
        length = len(nums)
        index = 0

        for i in range(0, length):
            if(nums[i] > 0):
                res[index] = nums[i]
                index = index+2

        index=1

        for i in range(0, length):
            if(nums[i]<=0):
                res[index] = nums[i]
                index = index+2

        return res