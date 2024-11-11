class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor_result = 0
        
        for num in nums:
            xor_result ^= num
        
        rightmost_set_bit = xor_result & -xor_result
        
        single1 = 0
        single2 = 0
        
        for num in nums:
            if num & rightmost_set_bit:
                single1 ^= num
            else:
                single2 ^= num
        
        return [single1, single2]
