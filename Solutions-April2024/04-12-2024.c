int* highest_left(int* height, int n)
{
    int* leftmax = (int*)malloc(n * sizeof(int));
    leftmax[0] = height[0];

    for(int i=1; i<n; i++){
        leftmax[i] = leftmax[i-1]>height[i] ? leftmax[i-1]:height[i];
    }
    return leftmax;
}

int* highest_right(int* height, int n)
{
    int* rightmax = (int*)malloc(n * sizeof(int));
    rightmax[n-1] = height[n-1];

    for(int i=n-2; i>=0; i--)
    {
        rightmax[i] = rightmax[i+1] > height[i] ? rightmax[i+1] : height[i];
    }
    return rightmax;
}

int trap(int* height, int heightSize) {
    int n = heightSize;

    if(n==1 || n==0)
    {
        return 0;
    }

    int* leftmax = highest_left(height, n);
    int* rightmax = highest_right(height, n);

    int sum = 0;

    for(int i=1; i<n-1; i++)
    {
        sum += (leftmax[i] < rightmax[i] ? leftmax[i] : rightmax[i]) - height[i];
    }
    free(leftmax);
    free(rightmax);

    return sum;
}