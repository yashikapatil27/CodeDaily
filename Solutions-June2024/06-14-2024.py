class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        # def increment(nums, freq):
        #     moves=0
        #     for i in range(len(nums)):
        #         if freq[nums[i]]>1:
        #             nums[i]+=1
        #             moves+=1
        #             freq[nums[i]-1]-=1
        #             freq[nums[i]]+=1
        #     return moves

        # freq = Counter(nums)
        # total_moves = 0
        
        # flag = (count == 1 for count in freq.values())

        # while any(count > 1 for count in freq.values()):
        #     total_moves += increment(nums, freq)
        
        # return total_moves

        nums.sort()
        moves=0

        for i in range(1, len(nums)):
            if nums[i] <= nums[i-1]:
                increment = nums[i-1]+1-nums[i]
                nums[i] += increment
                moves += increment
        
        return moves