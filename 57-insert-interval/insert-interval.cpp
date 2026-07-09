class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int n=intervals.size();
       if(n==0)
       {
        return {newInterval};
       }
       vector<vector<int>>v;
        int i=0;
        while(i<n && newInterval[0]>intervals[i][1])
        {
            v.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        int start=newInterval[0];
        int end=newInterval[1];
        while(i<n && end>=intervals[i][0])
        {
            start=min(start,intervals[i][0]);
            end=max(end,intervals[i][1]);
            i++;
        }
        v.push_back({start,end});
        while(i<n)
        {
            v.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return v;

    }
};