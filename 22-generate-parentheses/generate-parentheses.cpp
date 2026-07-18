class Solution {
public:
    void gp(string s,vector<string>&v,int o,int c,int n)
    {
        if(s.size()==2*n)
        {
            v.push_back(s);
            return;
        }
        if(o<n)
        gp(s+'(',v,o+1,c,n);
        if(c<o)
        gp(s+')',v,o,c+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        gp("",v,0,0,n);
        return v;
    }
};