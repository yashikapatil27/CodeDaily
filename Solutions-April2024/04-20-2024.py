class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        def dfs(r, c):
            land[r][c] = 0
            
            group[2] = max(group[2], r)
            group[3] = max(group[3], c)
            
            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and land[nr][nc] == 1:
                    dfs(nr, nc)

        m, n = len(land), len(land[0])
        result = []

        for i in range(m):
            for j in range(n):
                if land[i][j] == 1:
                    group = [i, j, i, j]
                    dfs(i, j)
                    result.append(group)

        return result
