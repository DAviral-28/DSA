class Solution {
public:
    void cs2(vector<int>&v,int i,int n,vector<int>&a,vector<vector<int>>&b)
    {
        if(n==0)
        {
            b.push_back(a);
            return;
        }
        for(int p=i;p<v.size();p++)
        {
            if(p>i && v[p]==v[p-1])
            continue;
            if(v[p]>n)
            break;
            a.push_back(v[p]);
            cs2(v,p+1,n-v[p],a,b);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>vv;
        sort(candidates.begin(),candidates.end());
        cs2(candidates,0,target,v,vv);
        return vv;
    }
};