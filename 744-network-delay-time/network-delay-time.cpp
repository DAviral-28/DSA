class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>q;
        q.push({0,k});
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        while(!q.empty())
        {
            int d=q.top().first;
            int node=q.top().second;
            q.pop();
            if(d>dis[node])
            continue;
            for(auto f: adj[node])
            {
                int x=f.first;
                int wt=f.second;
                if(d!=INT_MAX && d+wt<dis[x])
                {
                    dis[x]=d+wt;
                    q.push({dis[x],x});
                }
            }
        }
        int mm=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX)
            return -1;
            mm=max(mm,dis[i]);
        }
        return mm;
    }
};