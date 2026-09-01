class Solution {
public:
    int cc(vector<int>&v,vector<vector<int>>&dp,int i,int j)
    {
        if(i<0 || j<0)
        return 0;
        if(j==0)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        dp[i][j]=cc(v,dp,i-1,j)+cc(v,dp,i,j-v[i]);
        return dp[i][j];
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return cc(coins,dp,n-1,amount);
    }
};