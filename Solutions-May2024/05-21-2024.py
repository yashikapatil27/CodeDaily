class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        curr_subset = []

        def dfs(i):
            if i >= len(nums):
                res.append(curr_subset.copy())
                return
            
            # To choose the current number - Option 1
            curr_subset.append(nums[i])
            dfs(i+1)

            # To not choose the current number - Option 2
            curr_subset.pop()
            dfs(i+1)

        dfs(0)
        return res

