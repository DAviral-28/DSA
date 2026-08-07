class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int co=image[sr][sc];
        visited[sr][sc]=true;
        if(color==co)
        return image;
        image[sr][sc]=color;
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
                if(r>=0 && r<m && c>=0 && c<n && !visited[r][c] && image[r][c]==co)
                {
                    image[r][c]=color;
                    visited[r][c]=true;
                    q.push({r,c});
                }
            }
        }
        return image;
    }
};