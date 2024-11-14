class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        hash_remainder = {0:-1}
        total = 0

        for i, n in enumerate(nums):
            total += n
            r = total%k
            
            if r not in hash_remainder:
                hash_remainder[r] = i
            
            elif i-hash_remainder[r] > 1:
                return True
        return False