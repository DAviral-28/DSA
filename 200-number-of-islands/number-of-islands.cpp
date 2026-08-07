class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')
        return;
        visited[i][j]=true;
        grid[i][j]='0';
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j-1);
        dfs(grid,visited,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int p=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {

            
            if(grid[i][j]=='1')
            {
                p++;
                dfs(grid,visited,i,j);
            }
        }
                }
            return p;
    }
};