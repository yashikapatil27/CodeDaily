int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc((intervalsSize+1)*sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize+1)*sizeof(int));

    int idx = 0;
    int i;

    for(i=0; i<intervalsSize && intervals[i][1] < newInterval[0]; i++)
    {
        res[idx] = intervals[i];
        (*returnColumnSizes)[idx++] = *intervalsColSize;
    }

    while(i<intervalsSize && intervals[i][0] <=newInterval[1])
    {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        i++;
    }
    
    res[idx] = newInterval;
    (*returnColumnSizes)[idx++] = newIntervalSize;

    for(; i<intervalsSize; i++)
    {
        res[idx] = intervals[i];
        (*returnColumnSizes)[idx] = *intervalsColSize;
        idx++;
    }

    *returnSize = idx;
    return res;
}