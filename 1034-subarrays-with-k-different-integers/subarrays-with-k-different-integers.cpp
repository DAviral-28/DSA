class Solution {
public:
    int kd(vector<int>&v,int k)
    {
        if(k<0)
        return 0;
        unordered_map<int,int>m;
        int i=0,j=0;
        int c=0;
        while(j<v.size())
        {
            m[v[j]]++;
            while(m.size()>k)
            {
                m[v[i]]--;
                if(m[v[i]]==0)
                m.erase(v[i]);
                i++;
            }
            c+=(j-i+1);
            j++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kd(nums,k)-kd(nums,k-1);
    }
};