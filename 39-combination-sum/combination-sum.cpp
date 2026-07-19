class Solution {
public:
    void cs(vector<int>&v,int i,int s,vector<int>&a,vector<vector<int>>&b,int n)
    {
        if(s==n)
        {
            b.push_back(a);
            return ;
        }
        if(s>n || i==v.size())
        return ;
        a.push_back(v[i]);
        cs(v,i,s+v[i],a,b,n);
        a.pop_back();
        cs(v,i+1,s,a,b,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>vv;
        cs(candidates,0,0,vv,v,target);
        return v;
    }
};