int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int count=0;
    int product = 1;
    int i=0;

    for(int j=0; j<numsSize; j++)
    {
        product = product*nums[j];
        while(product>=k && i<=j)
        {
            product = product/nums[i++];
        }
        count += j-i+1;
    }
    return count;
}