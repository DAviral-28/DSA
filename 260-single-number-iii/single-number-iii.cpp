class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        ans=ans^nums[i];
        int rs=ans & (-ans);
        int b1=0,b2=0;
        for(int i=0;i<n;i++)
        {
            if((nums[i]&rs)!=0)
            b1=b1^nums[i];
            else
            b2=b2^nums[i];
        }
        return {b1,b2};
    }
};