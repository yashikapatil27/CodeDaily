int max(int a, int b) {
    return a > b ? a : b;
}

int findMaxLength(int* nums, int numsSize) {
    int maxlen = 0;
    int sum = 0;
    int* hashmap = (int*)malloc((2 * numsSize + 1) * sizeof(int));

    for(int i = 0; i <= 2 * numsSize; i++) 
    {
        hashmap[i] = -2;
    }
    hashmap[numsSize] = -1;

    int countZero = 0;
    int countOne = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] == 0) 
        {
            countZero++;
        } 
        else 
        {
            countOne++;
        }
    }

    if (countZero == 0 || countOne == 0) 
    {
        return 0;
    }

    for(int i = 0; i < numsSize; i++) 
    {
        sum += nums[i] == 0 ? -1 : 1;

        if (hashmap[sum + numsSize] != -2) 
        {
            maxlen = max(maxlen, i - hashmap[sum + numsSize]);
        } 
        else 
        {
            hashmap[sum + numsSize] = i;
        }
    }

    return maxlen;
}
