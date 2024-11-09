class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = Counter(nums)
        majority_element=0

        for num in nums:
            if count[num] >= len(nums)/2:
                majority_element = num
                break

        
        return majority_element

