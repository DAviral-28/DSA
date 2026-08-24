class Solution {
public:
    int cs(vector<int>&dp,int i)
    {
        if(i<=1)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        dp[i]=cs(dp,i-1)+cs(dp,i-2);
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return cs(dp,n);
    }
};