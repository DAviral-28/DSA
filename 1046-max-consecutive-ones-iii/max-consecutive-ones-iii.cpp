class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int m=0;
        int p=0;
        while(j<n)
        {
            if(nums[j]==0)
            p++;
            if(p>k)
            {
                while(i<n && nums[i]!=0)
                i++;
                i++;
                p--;
            }
            m=max(m,j-i+1);
            j++;
        }
        return m;
    }
};