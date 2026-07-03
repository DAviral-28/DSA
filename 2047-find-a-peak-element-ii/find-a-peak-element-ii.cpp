class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int rr=mat[0][mid];
            int r=0;
            for(int i=0;i<m;i++)
            {
                if(mat[i][mid]>rr)
                {
                    rr=mat[i][mid];
                    r=i;
                }
            }
            int left;
            int right;
            if(mid-1>=0)
            left=mat[r][mid-1];
            else 
            left=-1;
            if(mid+1<n)
            right=mat[r][mid+1];
            else 
            right=-1;
            if(mat[r][mid]>left && mat[r][mid]>right)
            return {r,mid};
            else if(mat[r][mid]<left)
            h=mid-1;
            else
            l=mid+1;
        }
        return {-1,-1};
    }
};