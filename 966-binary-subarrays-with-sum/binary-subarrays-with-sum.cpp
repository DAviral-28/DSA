class Solution {
public:
    int ans(vector<int>&nums , int p)
    {
        if(p<0)
        return 0;
        int n=nums.size();
        int s=0;
        int c=0;
        int i=0,j=0;
        while(j<n)
        {
            s+=nums[j];
            while(s>p)
            {
                s-=nums[i++];
            }
            c+=(j-i+1);
            j++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ans(nums,goal)-ans(nums,goal-1);
    }
};