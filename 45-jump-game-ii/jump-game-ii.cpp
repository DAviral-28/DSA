class Solution {
public:
    long long jmp(vector<int>&v,vector<int>&dp,int i)
    {
        if(i>=v.size()-1)
        return 0;
        if(v[i]==0)
        return INT_MAX-1;
        if(dp[i]!=-1)
        return dp[i];
        long long m=INT_MAX;
        for(int j=1;j<=v[i];j++)
        {
            m=min(m,1+jmp(v,dp,i+j));
        }
        dp[i]=m;
        return dp[i];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;
        vector<int>dp(n,-1);
        return jmp(nums,dp,0);
    }
};