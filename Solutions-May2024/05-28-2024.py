class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        curr_cost=0
        l=0
        res=0

        for r in range(len(s)):
            curr_cost += abs(ord(s[r])-ord(t[r]))

            while curr_cost > maxCost:
                curr_cost -= abs(ord(s[l]) - ord(t[l]))
                l+=1

            res = max(res, r-l+1)

        return res