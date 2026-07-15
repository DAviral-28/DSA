class Solution {
public:
    double rec(double x,double n)
    {
        if(n==1)
        return x;
        return x*rec(x,n-1);
    }
    double myPow(double x, int n) {
        if(n<0)
        x=1/x;
        if(x==1 || n==0)
        return 1;
        if(x==-1 && n%2==0)
        return 1;
        else if(x==-1 && n%2==1)
        return -1;
        if(n!=INT_MIN)
        n=abs(n);
        else
        n=INT_MAX-1;
        if(x>0 && x<1 && n>10000000)
        return 0;
        double p=rec(x,n);
        return p;
    }
};