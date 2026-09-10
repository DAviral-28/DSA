class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        //t=0
        vector<int>v;
        vector<int>v1;
        int n=position.size();
        bool flag=false;
        for(int i=1;i<n;i++)
        {
            while(i<n && position[i]-position[i-1]<=distance)
            {
                i++;
                if(i==n)
                flag=true;
            }
            v.push_back(position[i-1]);
            v1.push_back(speed[i-1]);
        }
        if(flag==false)
        {
            v.push_back(position[n-1]);
            v1.push_back(speed[n-1]);
        }
        int p=1;
        n=v.size();
        for(int i=n-1;i>0;i--)
        {
            if(v1[i]>=v1[i-1])
            p++;
            else
            v1[i-1]=v1[i];
        }
        return p;
    }
};