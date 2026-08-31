class Solution {
public:
    bool cc(vector<int>&v,int i,vector<vector<int>>&dp,int l)
    {
        if(i==v.size()-1)
        return true;
        if(i+1<v.size() && v[i+1]-v[i]>l+1)
        return false;
        if(dp[i][l]!=-1)
        return dp[i][l];
        bool a=false;
        bool b=false;
        bool c=false;
        int j=i;
        while(j+1<v.size() && v[j+1]-v[i]<=l+1)
        {
            if(j+1<v.size() && v[j+1]-v[i]==l-1)
            a=a || cc(v,j+1,dp,l-1);
            if(j+1<v.size() && v[j+1]-v[i]==l)
            b=b || cc(v,j+1,dp,l);
            if(j+1<v.size() && v[j+1]-v[i]==l+1)
            c=c || cc(v,j+1,dp,l+1);
            j++;
        }
        dp[i][l]= a||b||c;
        return dp[i][l];
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(2000,-1));
        return cc(stones,0,dp,0);
    }
};