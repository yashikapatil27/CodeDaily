class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = [defaultdict(int)]
        i = 0

        while i < len(formula):
            if formula[i] == '(':
                stack.append(defaultdict(int))
                i += 1
            elif formula[i] == ')':
                cur_map = stack.pop()
                i += 1
                count = ""
                while i < len(formula) and formula[i].isdigit():
                    count += formula[i]
                    i += 1
                count = 1 if not count else int(count)
                
                prev_map = stack[-1]
                for element in cur_map:
                    prev_map[element] += cur_map[element] * count
            else:
                element = formula[i]
                i += 1
                if i < len(formula) and formula[i].islower():
                    element += formula[i]
                    i += 1
                count = ""
                while i < len(formula) and formula[i].isdigit():
                    count += formula[i]
                    i += 1
                count = 1 if not count else int(count)
                
                stack[-1][element] += count
        
        count_map = stack[-1]
        res = ""
        for element in sorted(count_map.keys()):
            count = "" if count_map[element] == 1 else str(count_map[element])
            res += element + count

        return res
