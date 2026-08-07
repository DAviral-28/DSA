class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&visited , int i,int par,int c)
    {
        visited[i]=c;
        for(int x: graph[i])
        {
            if(visited[x]==-1)
            {
                if(c==0)
                {
                    if(!dfs(graph,visited,x,i,1))
                    return false; 
                }
                else
                {
                    if(!dfs(graph,visited,x,i,0))
                    return false;
                }
            }
            else
            {
                if(visited[x]==c)
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                if(!dfs(graph,visited,i,-1,0))
                return false;
            }
        }
        return true;
    }
};