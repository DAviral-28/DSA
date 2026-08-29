class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        int m=0;
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                if(r-l+1>m)
                {
                    m=r-l+1;
                    res=s.substr(l,m);
                }
                r++;
                l--;
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                if(r-l+1>m)
                {
                    m=r-l+1;
                    res=s.substr(l,m);
                }
                r++;
                l--;
            }
        }
        return res;
    }
};