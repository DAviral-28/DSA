class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        for(int i=0;i<(1<<n);i++)
        {
            vector<int>vv;
            for(int j=0;j<n;j++)
            {
                if(((1<<j)&i)!=0)
                vv.push_back(nums[j]);
            }
            v.push_back(vv);
        }
        return v;
    }
};