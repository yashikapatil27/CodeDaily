int pivotInteger(int n) {
    if (n == 1) {
        return 1;
    }

    int total_sum = (int)n*(n+1)/2;
    int current_sum = 0;

    for(int i=1; i<=n; i++)
    {
        current_sum += i;
        if(current_sum == total_sum - current_sum + i)
        {
            return i;
        }
    }
    return -1;
}
