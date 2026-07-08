class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int M=0,m=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                M+=1;
                m+=1;
            }
            else if(s[i]==')')
            {
                M-=1;
                m-=1;
               if(m<0)
               m=0;
            }
            else
            {
                if(m>0)
                m--;
                M+=1;
            }
            if(M<0)
            return false;
        }
            return m<=0 && M>=0;
        
    }
};