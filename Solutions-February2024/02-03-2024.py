class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        d = [0] * (n + 1)

        for i in range(1, n + 1):
            curr_max = 0
            for j in range(1, min(i, k) + 1):
                curr_max = max(curr_max, arr[i - j])
                d[i] = max(d[i], d[i - j] + curr_max * j)

        return d[n]

