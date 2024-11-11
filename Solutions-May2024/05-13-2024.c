int matrixScore(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int m = *gridColSize;

    for(int i=0; i<n; i++)
    {
        if(grid[i][0] == 0)
        {
            for(int j=0; j<m; j++)
            {
                grid[i][j] ^= 1;
            }
        }
    }

    for(int j=1; j<m; j++)
    {
        int colCount = 0;
        for(int i=0; i<n; i++)
        {
            colCount += grid[i][j];
        }

        if(colCount < n-colCount)
        {
            for(int i=0; i<n; i++)
            {
                grid[i][j] ^= 1;
            }
        }
    }

    int res = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            res += grid[i][j] * (1<<(m-1-j));
        }
    }
    return res;
}