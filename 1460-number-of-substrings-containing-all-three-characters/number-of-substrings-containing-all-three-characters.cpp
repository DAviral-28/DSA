class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        m['a']=-1,m['b']=-1,m['c']=-1;
        int i=0,j=0;
        int c=0;
        while(j<n)
        {
            m[s[j]]=j;
            if(m['a']!=-1 && m['b']!=-1 && m['c']!=-1)
            {
                i=min(m['a'],min(m['b'],m['c']));
                c+=i+1;
            }
            j++;
        }
        return c;
    }
};