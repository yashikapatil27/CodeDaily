class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        MOD = 10 ** 9 + 7
        # res = 0
        # new_array = []

        # for i in range(n):
        #     curr_sum=0
        #     for j in range(i, n):
        #         curr_sum = (curr_sum + nums[j]) % MOD
        #         new_array.append(curr_sum)
        
        # new_array.sort()
        # res = sum(new_array[left-1:right]) % MOD

        # return res

        min_heap = [(n, i) for i, n in enumerate(nums)]
        heapq.heapify(min_heap)

        res = 0
        for i in range(right):
            num, index = heapq.heappop(min_heap)
            if i >= left - 1:
                res = (res+num) % MOD

            if index + 1< n:
                next_pair = (num + nums[index+1], index+1)
                heapq.heappush(min_heap, next_pair)

        return res