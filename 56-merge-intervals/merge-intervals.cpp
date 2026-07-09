class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        vector<vector<int>>v;
        while(i<n)
        {
            if(i<n && end<intervals[i][0])
            {
                v.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else
            {
               end=max(end,intervals[i][1]);
            }
            i++;
        }
        v.push_back({start,end});
        return v;
    }
};