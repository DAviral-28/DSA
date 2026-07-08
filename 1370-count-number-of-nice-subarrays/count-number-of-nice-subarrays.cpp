class Solution {
public:
    int nos(vector<int>&v,int k)
    {
        int i=0,j=0;
        int c=0;
        while(j<v.size())
        {
            if(v[j]%2==1)
            k--;
            if(k<0)
            {
                while(v[i]%2!=1)
                i++;
                i++;
                k++;
            }
            c+=(j-i+1);
            j++;
        }
        return c;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return nos(nums,k)-nos(nums,k-1);
    }
};