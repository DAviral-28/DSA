class Solution {
public:
    int lcs(string &s1,string &s2,vector<vector<int>>&dp,int i,int j)
    {
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take=0;
        if(s1[i]==s2[j])
        take=1+lcs(s1,s2,dp,i-1,j-1);
        int nt=max(lcs(s1,s2,dp,i-1,j),lcs(s1,s2,dp,i,j-1));
        dp[i][j]=max(take,nt);
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return lcs(text1,text2,dp,m-1,n-1);
    }   
};