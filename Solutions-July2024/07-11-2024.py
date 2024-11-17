class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []

        for char in s:
            if char == ')':
                res = []
                while stack[-1] != '(':
                    res.append(stack.pop())
                stack.pop()
                stack.extend(res)
            else:
                stack.append(char)
        
        return "".join(stack)
