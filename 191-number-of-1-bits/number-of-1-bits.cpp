class Solution {
public:
    int hammingWeight(int n) {
        int p=0;
        while(n>0)
        {
            if(n%2==1)
            p++;
            n=n>>1;
        }
        return p;
    }
};