class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long s1=0,s2=0;
        for(int i=0;i<n;i++)
        {
            if(i<n/2)
            s1+=nums[i];
            else
            s2+=nums[i];
        }
        int i=(n/2)-1,j=n-1;
        int p=0;
        int q=0;
        while(j>=0)
        {
            if(s1>s2)
            p++;
            s1=s1+nums[j]-nums[i];
            s2=s2+nums[i]-nums[j];
            i=(i-1+n)%n;
            j--;
        }
        return p;
    }
};