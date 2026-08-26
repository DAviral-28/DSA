class Solution {
public:
    int md(string &s1,string &s2,vector<vector<int>>&dp,int i,int j)
    {
        if(i<0)
        return j+1;
        if(j<0)
        return i+1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]==s2[j])
        dp[i][j]=md(s1,s2,dp,i-1,j-1);
        else
        {
        int right=min(1+md(s1,s2,dp,i,j-1),1+md(s1,s2,dp,i-1,j));
        dp[i][j]=min(1+md(s1,s2,dp,i-1,j-1),right);
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return md(word1,word2,dp,m-1,n-1);
    }
};