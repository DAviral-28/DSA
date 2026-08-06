class Solution {
public:
    void dfs(vector<int>adj[] , vector<bool>&visited,int i)
    {
        visited[i]=true;
        for(int x : adj[i])
        {
            if(!visited[x])
            {
                dfs(adj,visited,x);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                p++;
                dfs(adj,visited,i);
            }
        }
        return p;
    }
};