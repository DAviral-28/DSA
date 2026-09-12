class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(i);
        }
        int p=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            vector<int>v=it->second;
            if(v.size()>=3)
            {
                int q=v[1]-v[0];
                bool flag=true;
                for(int i=1;i<v.size();i++)
                {
                    if(v[i]-v[i-1]!=q)
                    flag=false;
                }
                if(flag)
                p++;
            }
        }
        return p;
    }
};