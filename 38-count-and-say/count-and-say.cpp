class Solution {
public:
    string cas(string s,int i,int n)
    {
        if(i==n)
        return s;
        string ss="";
        int p=1;
        int k=0;
        while(k<s.size()-1)
        {
            if(s[k]==s[k+1])
            p++;
            else
            {
                ss+=to_string(p);
                ss.push_back(s[k]);
                p=1;
            }
            k++;
        }
        ss+=to_string(p);
        ss.push_back(s[s.size()-1]);
        return cas(ss,i+1,n);
    }
    string countAndSay(int n) {
        string s="1";
        return cas(s,1,n);
    }
};