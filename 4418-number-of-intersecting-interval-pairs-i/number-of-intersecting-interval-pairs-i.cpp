class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int p=0;
        for(int i=0;i<n-1;i++)
        {
            int j=i+1;
            while(j<n && intervals[i][1]>=intervals[j][0])
            {
                j++;
                p++;
            }
        }
        return p;
    }
};