class Solution {
public:
    bool issafe(int r,int c,vector<vector<string>>&ans,vector<string>v)
    {
        int dr=r;
        int dc=c;
        while(dr>=0 && dc>=0)
        {
            if(v[dr][dc]=='Q')
            return false;
            dr--;
            dc--; 
        }
        dr=r;
        dc=c;
        while(dc>=0)
        {
            if(v[dr][dc]=='Q')
            return false;
            dc--;
        }
        dr=r;
        dc=c;
        while(dr<v.size() && dc>=0)
        {
            if(v[dr][dc]=='Q')
            return false;
            dr++;
            dc--;
        }
        dr=r;
        dc=c;
           while(dr < v.size() && dc >= 0) {
            if(v[dr][dc] == 'Q')
                return false;

            dr++;
            dc--;
           }
        return true;
    }
    void solve(int n,int c, vector<vector<string>>&ans,vector<string>v)
    {
        if(c==n)
        {
            ans.push_back(v);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(issafe(i,c,ans,v))
            {
                v[i][c]='Q';
                solve(n,c+1,ans,v);
                v[i][c]='.';
            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>s;
        vector<string>v(n);
        string ss(n,'.');
        for(int i=0;i<n;i++)
        v[i]=ss;
        solve(n,0,s,v);
        return s;
    }
};