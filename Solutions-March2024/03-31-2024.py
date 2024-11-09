class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        res = 0
        bad_i = left_i = right_i = -1

        for i, num in enumerate(nums):
            if not minK <= num <= maxK:
                bad_i = i

            if num == minK:
                left_i = i

            if num == maxK:
                right_i = i

            res += max(0, min(left_i, right_i) - bad_i)

        return res
