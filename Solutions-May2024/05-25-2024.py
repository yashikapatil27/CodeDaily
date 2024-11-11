class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def backtrack(start, path):
            if start == len(s):
                res.append(' '.join(path))
                return
            for end in range(start+1, len(s)+1):
                if s[start:end] in wordSet:
                    backtrack(end, path+ [s[start:end]])
        
        wordSet = set(wordDict)
        res = []
        backtrack(0, [])
        return res