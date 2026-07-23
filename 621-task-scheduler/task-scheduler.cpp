class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        unordered_map<char,int>mp;
        int q=0;
        for(int i=0;i<m;i++)
        {
            mp[tasks[i]]++;
            if(mp[tasks[i]]>q)
            q=mp[tasks[i]];
        }
        int p=mp.size();
        int w=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {   
            if(it->second==q)
            w++;
        }
        return max(m,(n+1)*(q-1)+w);

    }
};