class Solution {
public:
    void swd(vector<int>&v,vector<int>&vv,set<vector<int>>&s,int i)
    {
        if(i==v.size())
        {
            s.insert(vv);
            return;
        }
        vv.push_back(v[i]);
        swd(v,vv,s,i+1);
        vv.pop_back();
        swd(v,vv,s,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>vv;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        swd(nums,vv,s,0);
        for(auto p : s)
        v.push_back(p);
        return v;
    }
};