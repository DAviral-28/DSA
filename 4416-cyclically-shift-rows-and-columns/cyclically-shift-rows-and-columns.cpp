class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        /*1 2 3 4 5 
        2 1 5 4 3
        3 4 5 1 2 */
        for(int i=0;i<n;i++)
        {
            int k=rowShift[i]%n;
            reverse(grid[i].begin(),grid[i].begin()+k);
            reverse(grid[i].begin()+k,grid[i].end());
            reverse(grid[i].begin(),grid[i].end());
        }
        for(int i=0;i<n;i++)
        {
            int k=colShift[i]%n;
            vector<int>v;
            for(int j=0;j<n;j++)
            {
                v.push_back(grid[j][i]);
            }
            reverse(v.begin(),v.begin()+k);
            reverse(v.begin()+k,v.end());
            reverse(v.begin(),v.end());
            for(int j=0;j<n;j++)
            grid[j][i]=v[j];
        }
        return grid;
    }
};