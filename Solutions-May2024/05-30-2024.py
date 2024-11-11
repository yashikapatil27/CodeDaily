class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)

        res = 0

        for i in range(n-1):
            curr = arr[i]
            for k in range(i+1, n):
                curr ^= arr[k]
                if curr == 0:
                    res += (k-i)
        return res           