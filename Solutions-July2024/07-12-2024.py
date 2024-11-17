class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def calculateGain(s, a, b, score):
            stack = []
            res = 0
            for char in s:
                if stack and char == b and stack[-1] == a:
                    stack.pop()
                    res += score
                else:
                    stack.append(char)
            return ''.join(stack), res
            
        if x>y:
            s, gain_x = calculateGain(s, 'a', 'b', x)
            _, gain_y = calculateGain(s, 'b', 'a', y)
        
        else:
            s, gain_y = calculateGain(s, 'b', 'a', y)
            _, gain_x = calculateGain(s, 'a', 'b', x)

        return gain_x + gain_y
            