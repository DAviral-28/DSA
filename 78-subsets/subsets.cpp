class Solution {
public:
    void ps(vector<int>&v,int i,vector<vector<int>>&vv,vector<int>&cur)
    {
        if(i==v.size())
        {
            vv.push_back(cur);
            return;
        }
        cur.push_back(v[i]);
        ps(v,i+1,vv,cur);
        cur.pop_back();
        ps(v,i+1,vv,cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        vector<int>cur;
        ps(nums,0,v,cur);
        return v;
    }
};