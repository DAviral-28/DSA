class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long pp=1;
        long long sp=1;
        int m=INT_MIN;
        for(int i=0;i<n;i++)
        {
            pp*=nums[i];
            sp*=nums[n-1-i];
            m=max(m,(int)max(pp,sp));
            if(pp==0)
            pp=1;
            if(sp==0)
            sp=1;
        }
        return m;
    }
};