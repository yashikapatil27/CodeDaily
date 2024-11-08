int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if(matrixSize == 0 || *matrixColSize == 0)
    {
        return 0;
    }

    int cols = *matrixColSize;
    int mx = 0;
    int *height = (int*)malloc(cols*sizeof(int));
    int *left = (int*)malloc(cols*sizeof(int));
    int* right = (int*)malloc(cols*sizeof(int));

    for(int i=0; i<cols; i++)
    {
        left[i] = 0;
        right[i] = cols;
        height[i] = 0;
    }

    for(int i=0; i<matrixSize; i++)
    {
        int current_left = 0;
        int current_right = cols; 

        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j] == '1')
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }

        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j] == '1')
            {
                left[j] = (left[j] > current_left) ? left[j] : current_left;
            }
            else
            {
                left[j] = 0;
                current_left = j + 1;
            }
        }

        for(int j=cols-1; j>=0; j--)
        {
            if(matrix[i][j] == '1')
            {
                right[j] = (right[j] < current_right) ? right[j] : current_right;
            }
            else
            {
                right[j] = cols;
                current_right = j;
            }
        }

        for(int j=0; j<cols; j++)
        {
            mx = (mx > (right[j] - left[j]) * height[j]) ? mx : (right[j] - left[j]) * height[j];
        }
    }

    free(height);
    free(left);
    free(right);

    return mx;
}
