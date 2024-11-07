long long countSubarrays(int* nums, int numsSize, int k) {
    long long count = 0;
    int max = nums[0];

    for(int i=1; i<numsSize; i++)
    {
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }
    
    int left=0, right=0, freq=0;

    while(right<numsSize)
    {
        if(nums[right] == max)
        {
            freq++;
        }
        right++;

        while(freq>=k && left<right)
        {
            count += numsSize - right + 1;

            if(nums[left] == max)
            {
                freq--;
            }
            left++;
        }
    }
    return count;
}
