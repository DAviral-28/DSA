class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0]=0;
        int a[4]={0,1,0,-1};
        int b[4]={1,0,-1,0};
        while(!q.empty())
        {
            int x=q.top().second.first;
            int y=q.top().second.second;
            int d=q.top().first;
            q.pop();
            if(d > dis[x][y])
            continue;
            for(int i=0;i<4;i++)
            {
                int r=x+a[i];
                int c=y+b[i];

    if(r < 0 || r >= m || c < 0 || c >= n)
        continue;
               int effort = max(d, abs(heights[r][c] - heights[x][y]));

if(effort < dis[r][c])
{
    dis[r][c] = effort;
    q.push({effort, {r, c}});
}
            }
        }
        return dis[m-1][n-1];
    }
};