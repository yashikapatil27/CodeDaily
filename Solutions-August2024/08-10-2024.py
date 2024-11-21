class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        rows1, cols1  = len(grid), len(grid[0])
        rows2, cols2 = 3*rows1, 3*cols1

        grid2 = [[0]*cols2 for _ in range(rows2)]

        for r1 in range(rows1):
            for c1 in range(cols1):
                r2, c2 = r1*3, c1*3
                if grid[r1][c1] == "/":
                    grid2[r2][c2+2] = 1
                    grid2[r2+1][c2+1] = 1
                    grid2[r2+2][c2] = 1
                elif grid[r1][c1] == "\\":
                    grid2[r2][c2] = 1
                    grid2[r2+1][c2+1] = 1
                    grid2[r2+2][c2+2] = 1
        def dfs(r, c, visited):
            if (r<0 or c<0 or r == rows2 or c == cols2 or 
            grid2[r][c]!=0 or (r,c) in visited):
                return

            visited.add((r,c))
            neighbors = [[r+1,c], [r,c+1], [r-1,c], [r,c-1]]

            for nr, nc in neighbors:
                dfs(nr, nc, visited)


        res = 0
        visited = set()
        for r in range(rows2):
            for c in range(cols2):
                if grid2[r][c] == 0 and (r,c) not in visited:
                    dfs(r, c, visited)
                    res += 1


        return res

