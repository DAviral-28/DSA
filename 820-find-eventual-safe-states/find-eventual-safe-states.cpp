class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j : graph[i])
            {
                adj[j].push_back(i);
            }
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(int x : adj[i])
            indegree[x]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int>v;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            v.push_back(node);
            for(int x : adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                q.push(x);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};