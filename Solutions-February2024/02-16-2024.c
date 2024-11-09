int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findLeastNumOfUniqueInts(int* arr, int arrSize, int k) {
    qsort(arr, arrSize, sizeof(int), compare);

    int uniqueCount = 0;
    int i = 0;

    while (i < arrSize) {
        int count = 1; 
        while (i + 1 < arrSize && arr[i] == arr[i + 1]) {
            i++;
            count++;
        }

        if (k >= count) {
            k -= count;
        } else {
            uniqueCount++;
        }
        i++;
    }

    return uniqueCount;
}