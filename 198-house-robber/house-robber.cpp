class Solution {
public:
    int hr(vector<int>&v,vector<int>&dp,int i)
    {
        if(i==0)
        return v[0];
        if(dp[i]!=-1)
        return dp[i];
        int nt=0+hr(v,dp,i-1);
        int t=v[i];
        if(i>1)
        t+=hr(v,dp,i-2);
        dp[i]=max(nt,t);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return hr(nums,dp,n-1);
    }
};