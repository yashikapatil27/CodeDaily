class Solution:
    def minimumPushes(self, word: str) -> int:
        count = [0]*26

        for c in word:
            count[ord(c) - ord("a")] += 1

        count.sort(reverse=True)

        #res = 0

        #for i, cnt in enumerate(count):
        #    res += cnt * (1 + i//8)

        res = sum(count[:8]) + 2*sum(count[8:16]) + 3*sum(count[16:24]) + 4*sum(count[24:])
        
        return res