class Solution {
public:
    int mps(vector<vector<int>>&v,vector<vector<int>>&dp,int i,int j)
    {
        if(i==0 && j==0)
        return v[0][0];
        if(i<0 || j<0)
        return INT_MAX;
        if(dp[i][j]!=-1)
        return dp[i][j];
        dp[i][j]=v[i][j]+min(mps(v,dp,i-1,j),mps(v,dp,i,j-1));
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return mps(grid,dp,m-1,n-1);
    }
};