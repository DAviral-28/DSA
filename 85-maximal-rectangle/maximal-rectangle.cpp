class Solution {
public:
     vector<int> findpse(vector<int>v)
    {
        int n=v.size();
        vector<int>vv(n);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                vv[i]=-1;
                s.push(i);
                continue;        
            }
        if(v[i]>v[s.top()])
        {
            vv[i]=s.top();
            s.push(i);
        }
        else
        {
            while(!s.empty() && v[i]<=v[s.top()])
            s.pop();
            if(s.empty())
            vv[i]=-1;
            else
            vv[i]=s.top();
            s.push(i);
        }
        }
        return vv;
    }
    vector<int> findnse(vector<int>v)
    {
        int n=v.size();
        vector<int>vv(n);
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                vv[i]=n;
                s.push(i);            
            }
        if(v[i]>v[s.top()])
        {
            vv[i]=s.top();
            s.push(i);
        }
        else
        {
            while(!s.empty() && v[i]<=v[s.top()])
            s.pop();
            if(s.empty())
            vv[i]=n;
            else
            vv[i]=s.top();
            s.push(i);
        }
        }
        return vv;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse=findnse(heights);
        vector<int>pse=findpse(heights);
        int m=0;
        for(int i=0;i<n;i++)
        {
            int left=pse[i];
            int right=nse[i];
            int a=((right-left-1)*1LL*heights[i]);
            m=max(m,a);
        }
        return m;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>v(n,0);
        int mm=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                v[j]=0;
                else
                v[j]++;
            }
            int ans=largestRectangleArea(v);
            mm=max(mm,ans);
        }
        return mm;
    }
};