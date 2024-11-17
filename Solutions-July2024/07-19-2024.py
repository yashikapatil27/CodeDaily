class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        rows = len(matrix)
        cols = len(matrix[0])

        max_in_col = [float('-inf')] * cols
        for c in range(cols):
            for r in range(rows):
                max_in_col[c] = max(matrix[r][c], max_in_col[c])

        min_in_row = [float('inf')] * rows
        for r in range(rows):
            for c in range(cols):
                min_in_row[r] = min(matrix[r][c], min_in_row[r])

        res = []
        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == min_in_row[r] and matrix[r][c] == max_in_col[c]:
                    res.append(min_in_row[r])
        
        return res