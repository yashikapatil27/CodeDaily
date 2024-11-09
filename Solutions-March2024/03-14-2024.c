int numSubarraysWithSum(int* nums, int numsSize, int goal) 
{
    int res = 0;
    int sum = 0;
    int prev_sums[30000];
    for (int i = 0; i < 30000; i++) 
    {
        prev_sums[i] = 0;
    }

    prev_sums[0] = 1;

    for (int i = 0; i < numsSize; i++) 
    {
        sum += nums[i];
        if (sum - goal >= 0) {
            res += prev_sums[sum - goal];
        }
        prev_sums[sum]++;
    }

    return res;
}
