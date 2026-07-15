class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>m;
        vector<int>v;
        int i=0,j=0;
        while(j<n)
        {
            m[nums[j]]++;
            k--;
            if(k<0)
            {
                m[nums[i]]--;
                if(m[nums[i]]==0)
                m.erase(nums[i]);
                k++;
                i++;
            }
            if(k==0)
            {
                v.push_back(m.rbegin()->first);
            }
            j++;
        }
        return v;
    }
};