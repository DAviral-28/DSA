class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int p=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' && p<0)
            {
                ans-=p;
                p=1;
            }
            else if(s[i]==')')
            p--;
            else 
            p++;
        } 
        ans+=abs(p);
        return ans;
    }
};