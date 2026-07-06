class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int i=0,j=n-1;
        int ls=0,rs=0;
        int m=0;
        for(int i=0;i<k;i++)
        ls+=cardPoints[i];
        if(k==n)
        return ls;
        int q=0;
        while(k>0)
        {
            m=max(m,ls+rs);
            ls-=cardPoints[k-1];
            rs+=cardPoints[n-1-q];
            k--;
            q++;
        }
        m=max(m,ls+rs);
        return m;
    }
};