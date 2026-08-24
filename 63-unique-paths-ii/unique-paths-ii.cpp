class Solution {
public:
    int upwo(vector<vector<int>>&v,vector<vector<int>>&dp,int i,int j)
    {
        if(i<0 || j<0 || v[i][j]==1)
        return 0;
        if(i==0 && j==0)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        dp[i][j]=upwo(v,dp,i-1,j)+upwo(v,dp,i,j-1);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return upwo(obstacleGrid,dp,m-1,n-1);
    }
};