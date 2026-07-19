class Solution {
public:
    void lc(string &s,string ss,int i,vector<string>&v)
    {
        if(i==s.size())
        {
            v.push_back(ss);
            return;
        }
        if(s[i]=='2')
        {
            lc(s,ss+'a',i+1,v);
            lc(s,ss+'b',i+1,v);
            lc(s,ss+'c',i+1,v);
        }
        else if(s[i]=='3')
        {
            lc(s,ss+'d',i+1,v);
            lc(s,ss+'e',i+1,v);
            lc(s,ss+'f',i+1,v);
        }
        else if(s[i]=='4')
        {
            lc(s,ss+'g',i+1,v);
            lc(s,ss+'h',i+1,v);
            lc(s,ss+'i',i+1,v);
        }
        else if(s[i]=='5')
        {
            lc(s,ss+'j',i+1,v);
            lc(s,ss+'k',i+1,v);
            lc(s,ss+'l',i+1,v);
        }
        else if(s[i]=='6')
        {
            lc(s,ss+'m',i+1,v);
            lc(s,ss+'n',i+1,v);
            lc(s,ss+'o',i+1,v);
        }
        else if(s[i]=='7')
        {
            lc(s,ss+'p',i+1,v);
            lc(s,ss+'q',i+1,v);
            lc(s,ss+'r',i+1,v);
            lc(s,ss+'s',i+1,v);
        }
        else if(s[i]=='8')
        {
            lc(s,ss+'t',i+1,v);
            lc(s,ss+'u',i+1,v);
            lc(s,ss+'v',i+1,v);
        }
        else
        {
            lc(s,ss+'w',i+1,v);
            lc(s,ss+'x',i+1,v);
            lc(s,ss+'y',i+1,v);
            lc(s,ss+'z',i+1,v);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>v;
        lc(digits,"",0,v);
        return v;
    }
};