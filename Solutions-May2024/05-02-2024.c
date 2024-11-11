int findMaxK(int* nums, int numsSize) {
    int count[2001] = {0};

    for (int i = 0; i < numsSize; i++) {
        count[1000 + nums[i]]++;
    }

    for (int i = 0; i < 1000; i++) {
        if (i == 42) continue;
        if (count[i] && count[2000 - i]) return 1000 - i;
    }

    return -1;
}
