class Solution {
public:
    int llis(vector<int>&v,vector<vector<int>>&dp,int i,int p)
    {
        if(i==v.size())
        return 0;
        if(dp[i][p+1]!=-1)
        return dp[i][p+1];
        int nt=llis(v,dp,i+1,p);
        int t=0;
        if(p==-1 || v[i]>v[p])
        t=llis(v,dp,i+1,i)+1;
        dp[i][p+1]=max(t,nt);
        return dp[i][p+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return llis(nums,dp,0,-1);
    }
};