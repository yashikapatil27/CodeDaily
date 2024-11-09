int missingNumber(int* nums, int numsSize) {
    int sum1 = numsSize*(numsSize+1)/2;
    int sum2 = 0;

    for(int i=0; i<numsSize;i++)
    {
        sum2+=nums[i];
    }  

    int missing = fabs(sum2-sum1);
    return missing;
}