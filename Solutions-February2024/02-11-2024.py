class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        table = {}

        def func(row, col1, col2):
            if (row, col1, col2) in table:
                return table[(row, col1, col2)]

            if row == rows-1:
                if col1!=col2:
                    return grid[row][col1]+grid[row][col2]
                else:
                    return 0

            count = 0
            for i in [-1, 0, 1]:
                for j in [-1, 0, 1]:
                    col1_new, col2_new = col1+i, col2+j
                
                    if 0<= col1_new < cols and 0<= col2_new < cols:
                        count = max(count, func(row+1, col1_new, col2_new))

            if col1!=col2:
                count += grid[row][col1]+grid[row][col2]

            table[row, col1, col2] = count
            return count

        return func(0,0,cols-1)
