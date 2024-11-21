class Solution:
    def countSeniors(self, details: List[str]) -> int:
        res = 0
        for p in details:
            if (int(p[11] + p[12]) > 60):
                res += 1
        
        return res