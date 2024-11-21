from typing import List

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def isMagic(x, y):
            s = set()
            for i in range(3):
                for j in range(3):
                    num = grid[x+i][y+j]
                    if num < 1 or num > 9 or num in s:
                        return False
                    s.add(num)
            if sum(grid[x][y:y+3]) == 15 and \
               sum(grid[x+1][y:y+3]) == 15 and \
               sum(grid[x+2][y:y+3]) == 15 and \
               sum([grid[x+i][y] for i in range(3)]) == 15 and \
               sum([grid[x+i][y+1] for i in range(3)]) == 15 and \
               sum([grid[x+i][y+2] for i in range(3)]) == 15 and \
               grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2] == 15 and \
               grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y] == 15:
                return True
            return False

        rows, cols = len(grid), len(grid[0])
        count = 0

        for i in range(rows - 2):
            for j in range(cols - 2):
                if grid[i+1][j+1] == 5 and isMagic(i, j):
                    count += 1

        return count
