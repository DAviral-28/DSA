class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int p=0;
        int i=0;
        int start=intervals[0][0];
        int end=intervals[0][1];
        i++;
        while(i<n)
        {
            if(end<=intervals[i][0])
            {
                end=intervals[i][1];
            }
            else
            {
                p++;
                end=min(end,intervals[i][1]);
            }
            i++;
        }
        return p;
    }
};