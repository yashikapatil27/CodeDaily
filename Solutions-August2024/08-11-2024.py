class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        

        def dfs(r, c, visited):
            if (r<0 or c<0 or r==rows or c == cols or 
                grid[r][c] == 0 or (r,c) in visited):
                return
            visited.add((r,c))
            nei = [[r+1, c], [r, c+1], [r-1, c], [r, c-1]]
            for nr, nc in nei:
                dfs(nr, nc, visited)

        def count_islands():
            visited = set()
            count = 0
            for r in range(rows):
                for c in range(cols):
                    if grid[r][c] and (r,c) not in visited:
                        dfs(r, c, visited)
                        count += 1

            return count
            
        if count_islands() != 1:
            return 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    continue
                grid[r][c] = 0
                if count_islands() != 1:
                    return 1

                grid[r][c] = 1
        return 2
