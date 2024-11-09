class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.length(), ans=0;

        vector<int> dp(26,0);

        for(int i=0; i<n; i++)
        {
            int maxLength = 0;
            for(char last='a'; last<='z'; last++)
            {
                if(abs(s[i] - last)<=k)
                {
                    maxLength = max(maxLength, 1+dp[last-'a']);
                }
            }
            dp[s[i] - 'a'] = maxLength;
            ans = max(ans, maxLength);
        }
        return ans;
    }
};

