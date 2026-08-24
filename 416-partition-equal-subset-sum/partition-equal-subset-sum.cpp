class Solution {
public:
    bool cp(vector<int>&v,vector<vector<int>>&dp,int t,int i)
    {
        if(t<0)
        return false;
        if(t==0)
        return true;
        if(i<0)
        return false;
        if(dp[i][t]!=-1)
        return dp[i][t];
        dp[i][t]=cp(v,dp,t-v[i],i-1) || cp(v,dp,t,i-1);
        return dp[i][t];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++)
        s+=nums[i];
        if(s%2!=0)
        return false;
        int target=s/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return cp(nums,dp,target,n-1);
    }
};