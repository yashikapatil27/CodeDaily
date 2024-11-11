int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    qsort(happiness, happinessSize, sizeof(int), compare);

    long long max = 0;
    int decrement = 0;

    for(int i=0; i<happinessSize; i++)
    {
        int diff = happiness[i] - decrement;

        if(k<=0 || diff <=0)
        {
            break;
        }
        max += diff;
        decrement++;
        k--;
    }
    return max;
}   