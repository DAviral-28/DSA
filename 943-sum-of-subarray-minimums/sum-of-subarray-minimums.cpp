class Solution {
public:
    vector<int> findnse(vector<int>&v)
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
                vv[i]=n;
                else
                vv[i]=s.top();
                s.push(i);
            }
            
        }
        return vv;
    }
    vector<int> findpsee(vector<int>&v)
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
            if(v[i]>=v[s.top()])
            {
                vv[i]=s.top();
                s.push(i);
            }
            else
            {
                while(!s.empty() && v[i]<v[s.top()])
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
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);
        int sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            int right=nse[i]-i;
            int left=i-psee[i];
            sum=(sum + (right*left*1LL*arr[i])%mod)%mod;
        }
        return sum;
    }
};