class Solution {
public:
    long long recs(string &s,int i,long long sum,bool flag)
    {
        if(sum>=INT_MAX && flag==false)
        return INT_MAX;
        else if(sum>=(long long)INT_MAX+1 && flag==true)
        return INT_MIN;
        if(i==s.size() || !((s[i]-'0')>=0 && (s[i]-'0')<=9))
        return sum;
        return recs(s,i+1,10*sum+(s[i]-'0'),flag);
    }
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ')
        i++;
        bool flag=false;
        if(s[i]=='-')
        {
            flag=true;
            i++;
        }
        else if(s[i]=='+')
        i++;
        long long sum=0;
        if(flag==true)
        return -recs(s,i,sum,flag);
        return recs(s,i,sum,flag);
    }
};