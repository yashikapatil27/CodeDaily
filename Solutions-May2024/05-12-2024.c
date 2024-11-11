int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int N = gridSize;
    int** res = (int**)malloc((N - 2) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((N - 2) * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < N - 2; i++) {
        int* row = (int*)malloc((N - 2) * sizeof(int));
        (*returnColumnSizes)[i] = N - 2;
        for (int j = 0; j < N - 2; j++) {
            int local_max = grid[i][j];
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    local_max = local_max > grid[r][c] ? local_max : grid[r][c];
                }
            }
            row[j] = local_max;
        }
        res[*returnSize] = row;
        (*returnSize)++;
    }

    return res;
}
