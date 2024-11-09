int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize; 

    for (int i = temperaturesSize - 1; i >= 0; i--) {
        int j = i + 1;

        while (j < temperaturesSize && temperatures[i] >= temperatures[j]) {
            if (result[j] > 0) {
                j = j + result[j];
            } else {
                j = temperaturesSize;
            }
        }

        if (j < temperaturesSize) {
            result[i] = j - i;
        } else {
            result[i] = 0; 
        }
    }

    return result;
}