void getSubsets(int* nums, int numsSize, int index, int curr, int* total)
{
    if(index == numsSize)
    {
        *total += curr;
        return;
    }

    getSubsets(nums, numsSize, index+1, curr^nums[index], total);
    getSubsets(nums, numsSize, index+1, curr, total);
}

int subsetXORSum(int* nums, int numsSize) {
    int total = 0;
    getSubsets(nums, numsSize, 0, 0, &total);
    return total;    
}