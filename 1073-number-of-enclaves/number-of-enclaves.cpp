class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int t=0,w=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    t++;
                    if(i==0 || i==m-1 || j==0 || j==n-1)
                    {
                        q.push({i,j});
                        visited[i][j]=true;
                        w++;
                    }
                }
            }
        }
        int a[4]={0,-1,0,1};
        int b[4]={1,0,-1,0};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r=x+a[i];
                int c=y+b[i];
                if(r>=0 && r<m && c>=0 && c<n && !visited[r][c] && grid[r][c]==1)
                {
                    q.push({r,c});
                    visited[r][c]=true;
                    w++;
                }
            }
        }
        return t-w;
    }
};