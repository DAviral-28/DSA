class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(i==n-1)
            return true;
            if(i!=n-1 && nums[i]==0)
            return false;
            int p=nums[i];
            int j=0;
            while(j<p)
            {
                if(i<n && nums[i]==n-1-i)
                return true;
                i++;
                j++;
                if(i<n && nums[i]>=p)
                {
                    p=nums[i];
                    j=0;
                }
            }
        }
        return true;
    }
};