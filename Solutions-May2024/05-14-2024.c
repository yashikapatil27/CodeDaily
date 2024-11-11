int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int dfs(int r, int c, int** grid, int rows, int columns)
{
    if(min(r,c)<0 || r==rows || c==columns || grid[r][c] == 0)
    {
        return 0;
    }

    int tmp = grid[r][c];
    grid[r][c] = 0;
    int res = 0;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    for(int i=0; i<4; i++)
    {
        int r2 = r + dr[i];
        int c2 = c + dc[i];
        res = max(res, tmp+dfs(r2, c2, grid, rows, columns));
    }

    grid[r][c] = tmp;
    return res;  
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int columns = *gridColSize;
    int res = 0;

    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<columns; c++)
        {
            res = max(res, dfs(r,c, grid, rows, columns));
        }
    }
    return res;
}