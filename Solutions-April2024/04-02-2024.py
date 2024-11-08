class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapST = {}
        mapTS = {}

        for i in range(len(s)):
            char1 = s[i]
            char2 = t[i]
            
            if (char1 in mapST and mapST[char1] != char2) or (char2 in mapTS and mapTS[char2] != char1):
                return False
            mapST[char1] = char2
            mapTS[char2] = char1
        return True
