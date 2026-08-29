class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int p=0;
        for(int i=0;i<n;i++)
        {
            string ss="";
            vector<int>f(26);
            for(int j=i;j<n;j++)
            {
                ss.push_back(s[j]);
                f[s[j]-'a']++;
                int m=INT_MAX,M=INT_MIN;
                for(int i=0;i<26;i++)
                {
                    if(f[i]>0)
                    {
                        M=max(M,f[i]);
                        m=min(m,f[i]);
                    }
                }
                f.clear();
                p+=M-m;
            }
        }
        return p;
    }
};