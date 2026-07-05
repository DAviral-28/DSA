class Solution {
public:
    int minBitFlips(int start, int goal) {
        int p=0;
        while(start>0 && goal>0)
        {
            if(start%2!=goal%2)
            p++;
            start=start>>1;
            goal=goal>>1;
        }
        while(start>0)
        {
            if(start%2==1)
            p++;
            start=start>>1;
        }
        while(goal>0)
        {
            if(goal%2==1)
            p++;
            goal=goal>>1;
        }
        return p;

    }
};