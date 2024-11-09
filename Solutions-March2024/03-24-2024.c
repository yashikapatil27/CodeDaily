int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findDuplicate(int* nums, int numsSize) {
    int duplicate = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == nums[i+1])
        {
            duplicate = nums[i];
            break;
        }
    }
    return duplicate;
}