class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        min_patches = 0
        max_num = 0
        i = 0
        length = len(nums)

        while max_num < n:
            if i<length and (max_num+1 >= nums[i]):
                max_num += nums[i]
                i += 1
            else:
                min_patches += 1
                max_num += (max_num+1)

        return min_patches
        