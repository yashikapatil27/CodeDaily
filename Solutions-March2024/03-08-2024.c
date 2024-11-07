int maxFrequencyElements(int* nums, int numsSize) {
    int max=nums[0];

    for(int i=1; i<numsSize; i++)
    {
        if(nums[i]>max)
        {
            max=nums[i];
        }
    }
    int* freq = (int*)malloc((max+1)*sizeof(int));

    for(int i=0; i<=max; i++)
    {
        freq[i] = 0;
    }

    for(int i=0; i<numsSize; i++)
    {
        freq[nums[i]]++;
    }

    int freq_max = freq[0];
    for(int i=1; i<=max; i++)
    {
        if(freq[i]>freq_max)
        {
            freq_max=freq[i];
        }
    }
    
    int count=0;
    for(int i=0; i<=max; i++)
    {
        if(freq[i] == freq_max)
        {
            count+=freq[i];
        }
    }

    free(freq);
    return count;

}