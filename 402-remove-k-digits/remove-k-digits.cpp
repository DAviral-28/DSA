class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        int n=num.size();
        if(k==n)
        return "0";
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && k>0 && (s.top()-'0')>(num[i]-'0'))
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0)
        {
            s.pop();
            k--;
        }
        string ss="";
        if(s.empty())
        return "0";
        while(!s.empty())
        {
            ss+=s.top();
            s.pop();
        }
        while(ss.size()>0 && ss[ss.size()-1]=='0')
        ss.pop_back();
        reverse(ss.begin(),ss.end());
        if(ss.empty())
        return "0";
        return ss;
    }
};