class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(string:str) -> bool:
            return string==string[::-1]

        def backtrack(start:int, path: List[str]):
            if start == len(s):
                result.append(path[:])

            for end in range(start+1, len(s)+1):
                substr = s[start:end]
                if isPalindrome(substr):
                    path.append(substr)
                    backtrack(end, path)
                    path.pop()

        result = []
        backtrack(0, [])
        return result