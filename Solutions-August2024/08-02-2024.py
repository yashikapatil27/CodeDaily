class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        N = len(nums)
        max_ones = 0
        ones_in_window = 0
        total_ones = nums.count(1)
        l = 0

        for r in range(2*N):
            if nums[r%N]:
                ones_in_window += 1
            
            if r-l+1 > total_ones:
                ones_in_window -= nums[l%N]
                l += 1

            max_ones = max(max_ones, ones_in_window)

        return total_ones - max_ones

