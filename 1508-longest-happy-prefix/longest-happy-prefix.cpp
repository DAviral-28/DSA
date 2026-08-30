class Solution {
public:
    string longestPrefix(string s) {
        string s1=s;
        string s2=s;
        int n=s.size();
        int i=n-1;
        while(i>0)
        {
            s1.erase(0,1);
            s2.pop_back();
            if(s1==s2)
            return s1;
        }
        return "";
    }
};