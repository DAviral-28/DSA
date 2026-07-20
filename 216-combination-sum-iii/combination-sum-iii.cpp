class Solution {
public:
    void cs3(int s,int k,int n,vector<int>&v,vector<vector<int>>&vv,int p)
    {
        if(s>n)
        return;
        if(k==0)
        {
        if(s==n)
            vv.push_back(v);
            return;
        }
        for(int i=p;i<=9;i++)
        {
            v.push_back(i);
            cs3(s+i,k-1,n,v,vv,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        vector<vector<int>>vv;
        cs3(0,k,n,v,vv,1);
        return vv;
    }
};