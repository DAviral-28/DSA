class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        vector<vector<int>> temoravlin = intervals;

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        // Store all end points
        vector<int> ends;

        for (auto &v : intervals) {
            ends.push_back(v[1]);
        }

        sort(ends.begin(), ends.end());

        long long total = 1LL * n * (n - 1) / 2;

        long long nonIntersecting = 0;

        for (int i = 0; i < n; i++) {

            int start = intervals[i][0];

            // Number of end points < start
            int cnt = lower_bound(ends.begin(), ends.end(), start)
                      - ends.begin();

            nonIntersecting += cnt;
        }

        return total - nonIntersecting;
    }
};