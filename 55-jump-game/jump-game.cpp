class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return true;
        int m=0;
        for(int i=0;i<n-1;i++)
        {
            m=max(m,i+nums[i]);
            if(m>=n-1)
            return true;
            if(m==i)
            return false;
        }
        return false;
    }
};