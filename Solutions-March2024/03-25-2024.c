int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* freq = (int*)calloc(numsSize + 1, sizeof(int));

    for(int i=0; i<numsSize; i++)
    {
        freq[nums[i]]++;
    }

    int count=0;

    for(int i=0; i<=numsSize; i++)
    {
        if(freq[i]>1)
        {
            count++;
        }
    }

    int* res = (int*)malloc(count*sizeof(int));
    int idx = 0;

    for(int i=1; i<=numsSize; i++)
    {
        if(freq[i]>1)
        {
            res[idx] = i;
            idx++;
        }
    }

    free(freq);
    *returnSize = count;
    return res;
}