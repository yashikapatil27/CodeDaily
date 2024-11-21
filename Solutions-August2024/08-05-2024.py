class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        count = Counter(arr)
        res = []

        for c in count.keys():
            if (count[c] == 1):
                res.append(c)

        if k <= len(res) and k>0:
            return res[k-1]
        
        return ""