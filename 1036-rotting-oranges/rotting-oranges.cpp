class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        int c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
                if(grid[i][j]==1)
                c++;
            }
        }
        int tt=0;
        int a[4]={0,1,0,-1};
        int b[4]={1,0,-1,0};
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tt=max(t,tt);
            for(int i=0;i<4;i++)
            {
                if(x+a[i]>=0 && x+a[i]<m && y+b[i]>=0 && y+b[i]<n && grid[x+a[i]][y+b[i]]==1 && !visited[x+a[i]][y+b[i]])
                {
                    q.push({{x+a[i],y+b[i]},t+1});
                    visited[x+a[i]][y+b[i]]=true;
                    c--;
                }
            }
        }
        if(c!=0)
        return -1;
        return tt;
    }
};