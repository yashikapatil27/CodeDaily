class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        remove_indices = set()
        
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif char == ')':
                if not stack:
                    remove_indices.add(i)
                else:
                    stack.pop()
        remove_indices.update(stack)
        
        result = ''
        for i, char in enumerate(s):
            if i not in remove_indices:
                result += char
        
        return result
