class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        int p=0;
        unordered_map<int,int>m;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                if(i-m.find(nums[i])->second!=1)
                {
                    if(s.find(nums[i])==s.end())
                    p--;
                    s.insert(nums[i]);
                }
            }
            m[nums[i]]=i;
        }
        return m.size()+p;
    }
};