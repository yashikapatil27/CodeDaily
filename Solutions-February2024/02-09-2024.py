class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        N = len(nums)
        output = [[num] for num in nums]

        for i in range (N):
            for j in range (i):
                if nums[i]%nums[j] == 0 and len(output[i]) < len(output[j])+1:
                    output[i] = output[j] + [nums[i]]
        
        return max(output, key = lambda x: len(x))
