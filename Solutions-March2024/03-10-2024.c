/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int* res = (int*)malloc(nums1Size*sizeof(int));
    for(int i=0; i<nums1Size; i++)
    {
        res[i] = 0;
    }
    int k=0;

    for(int i=0; i<nums1Size; i++)
    {
        int duplicate=0;
        for(int j=0; j<nums2Size; j++)
        {
            if(nums1[i] == nums2[j])
            {
                for(int m=0; m<k; m++)
                {
                    if(nums1[i] == res[m])
                    {
                        duplicate=1;
                        break;
                    }
                }

                if(!duplicate)
                {
                    res[k++] = nums1[i];
                    
                }
                break;
                
            }
        }
    }
    *returnSize=k;
    return res;
}