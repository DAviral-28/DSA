class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        return 1;
        if(x==1)
        return 1;
        if(n==INT_MIN && x==-1)
        return 1;
        else if(n==INT_MAX && x==-1)
        return -1;

        if(x==-1 && n&2==0)
        return 1;
        else if(x==-1 && n%2==1) return -1;
         if(n==INT_MIN)
        return 0;
        if(n>0)
        {
            double p=x;
            while(n>1)
            {
                x*=p;
                n--;
            }
        }
        else
        {
            x=1/x;
            n=abs(n);
            double p=x;;
            while(n>1)
            {
                x*=p;
                n--;
            }
        }
        return x;
    }
};