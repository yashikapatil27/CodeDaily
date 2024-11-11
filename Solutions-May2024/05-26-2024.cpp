#define mod 1000000007
class Solution {
public:
    int checkRecord(int n) {
        vector<vector<int>> dp(3, vector<int>(4,0));
        vector<vector<int>>prevDp(3, vector<int>(4,0));

        for(int ac=0; ac<=1; ac++)
        {
            for(int clc=0; clc<=2; clc++)
            {
                prevDp[ac][clc] = 1;
            }
        }

        for(int day=1; day<=n; day++)
        {
            for(int ac=0; ac<=1; ac++)
            {
                for(int clc=0; clc<=2; clc++)
                {
                    dp[ac][clc] = (prevDp[ac][0])%mod;
                    dp[ac][clc] = (dp[ac][clc] + prevDp[ac+1][0])%mod;
                    dp[ac][clc] = (dp[ac][clc] + prevDp[ac][clc+1])%mod;
                }
            }
            prevDp = dp;
        }
        return dp[0][0];
    }
};