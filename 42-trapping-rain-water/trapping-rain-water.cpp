class Solution {
public:
    vector<int> pre(vector<int>&v)
    {
        int n=v.size();
        vector<int>vv(n);
        vv[0]=v[0];
        for(int i=1;i<n;i++)
        {
            vv[i]=max(vv[i-1],v[i]);
        }
        return vv;
    }
    vector<int> suf(vector<int>&v)
    {
        int n=v.size();
        vector<int>vv(n);
        vv[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            vv[i]=max(vv[i+1],v[i]);
        }
        return vv;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        int sum=0;
        vector<int>pm=pre(height);
        vector<int>sm=suf(height);
        for(int i=0;i<n;i++)
        {
            int left=pm[i];
            int right=sm[i]; 
            if(height[i]<left && height[i]<right)
            {
                sum+=min(left,right)-height[i];
            }
        }
        return sum;
    }
};