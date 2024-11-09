int numSquares(int n) {
    long long int dp[n+1];
    dp[0] = 0;

    for(int i=1; i<=n; i++)
    {
        dp[i] = INT_MAX;
        for(int j=1; j*j <= i; j++)
        {
            if(dp[i] > 1+ dp[i - j*j])
            {
                dp[i] = 1+dp[i - j*j];
            }
        }
    }
    return dp[n];
}