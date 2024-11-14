class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        max_queue = deque()
        min_queue = deque()

        l=0
        res=0

        for r in range(len(nums)):
            while min_queue and nums[r] < min_queue[-1]:
                min_queue.pop()
            min_queue.append(nums[r])
            
            while max_queue and nums[r] > max_queue[-1]:
                max_queue.pop()
            max_queue.append(nums[r])

            while max_queue and min_queue and max_queue[0] - min_queue[0] > limit:
                if nums[l] == max_queue[0]:
                    max_queue.popleft()
                if nums[l] == min_queue[0]:
                    min_queue.popleft()
                l+=1 

            res = max(res, r-l+1)

        return res