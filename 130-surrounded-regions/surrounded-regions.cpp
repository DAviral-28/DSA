class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                visited[i][0]=true;
            }
            if(board[i][n-1]=='O')
            {
                q.push({i,n-1});
                visited[i][n-1]=true;
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if(board[0][i]=='O')
            {
                q.push({0,i});
                visited[0][i]=true;
            }
            if(board[m-1][i]=='O')
            {
                q.push({m-1,i});
                visited[m-1][i]=true;
            }
        }
        int a[4]={0,-1,0,1};
        int b[4]={1,0,-1,0};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            board[x][y]='A';
            for(int i=0;i<4;i++)
            {
                int r=x+a[i];
                int c=y+b[i];
                if(r>=0 && r<m && c>=0 && c<n && !visited[r][c] && board[r][c]=='O')
                {
                    q.push({r,c});
                    visited[r][c]=true;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';
                else if(board[i][j]=='A')
                board[i][j]='O';
            }
        }
    }
};