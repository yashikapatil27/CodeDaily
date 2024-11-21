class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []

        def backtrack(i, curr, total):  #dfs
            if total == target:
                res.append(curr.copy())
                return

            if total > target or i == len(candidates):
                return

            # include candidates[i]
            curr.append(candidates[i])
            backtrack(i+1, curr, total + candidates[i])
            curr.pop()

            # skip candidates[i]
            while (i < len(candidates) - 1) and (candidates[i] == candidates[i+1]):
                i += 1

            backtrack(i+1, curr, total)

        backtrack(0, [], 0)

        return res