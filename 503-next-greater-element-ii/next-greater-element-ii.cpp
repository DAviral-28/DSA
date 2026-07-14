class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        stack<int>s;
        int a=nums[0];
        for(int i=n;i<2*n;i++)
        {
            nums.push_back(nums[i-n]);
        }
        for(int i=2*n-1;i>=n;i--)
        {
            if(s.empty() || s.top()>nums[i])
            s.push(nums[i]);
            else
            {
                while(!s.empty() && nums[i]>=s.top())
                s.pop();
                s.push(nums[i]);
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                v[i]=-1;
                s.push(nums[i]);
                continue;
            }
            if(nums[i]>=s.top())
            {
                while(!s.empty() && nums[i]>=s.top())
                s.pop();
                if(s.empty())
                {
                    v[i]=-1;
                    s.push(nums[i]);
                }
                else
                {
                    v[i]=s.top();
                    s.push(nums[i]);
                }
            }
            else
            {
                v[i]=s.top();
                s.push(nums[i]);
            }
        }
        return v;
    }
};