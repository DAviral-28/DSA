class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())
        return "";
        unordered_map<char,int>m;
        int i=0,j=0;
        int ml=1e9,sl=-1;
        for(int i=0;i<t.size();i++)
        m[t[i]]++;
        int ctr=0;
        while(j<s.size())
        {
            if(m[s[j]]>0)
            {
                ctr++;
            }
            m[s[j]]--;
            while(ctr==t.size())
            {
                if(j-i+1<ml)
                {ml=j-i+1;
                sl=i;
                }
                m[s[i]]++;
                if(m[s[i]]>0)
                ctr--;
                i++;
            }
            j++;
        }
        if(sl==-1)
        return "";
        return s.substr(sl,ml);
    }
};