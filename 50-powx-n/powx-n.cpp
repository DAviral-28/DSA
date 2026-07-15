class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
        {
            x=1/x;
            if(n==INT_MIN)
            n=INT_MAX-1;
            else
            n=abs(n);
        }
        if(n==0)
        return 1;
        double h=myPow(x,n/2);
        if(n%2==0)
        return h*h;
        return x*h*h;
    }
};