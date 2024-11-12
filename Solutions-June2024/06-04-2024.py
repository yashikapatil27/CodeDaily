class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = Counter(s)
        res = 0
        flag = False

        for i, j in count.items():
            if j%2 == 0:
                res += j
            else:
                res += (j-1)
                flag = True

        if flag:
            res += 1

        return res