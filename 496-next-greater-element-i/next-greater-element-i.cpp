class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int,int>mp;
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                s.push(nums2[i]);
                mp[nums2[i]]=-1;
                continue;
            }
            if(s.top()>nums2[i])
            mp[nums2[i]]=s.top();
            else
            {
                while(!s.empty() && nums2[i]>=s.top())
                s.pop();
                if(s.empty())
                mp[nums2[i]]=-1;
                else
                mp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        vector<int>v(m);
        for(int i=0;i<m;i++)
        {
            v[i]=mp.find(nums1[i])->second;
        }
        return v;
    }
};