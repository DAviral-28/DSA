class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int a=source[0]-target[0];
        int b=source[1]-target[1];
        int p=a+b;
        if(a==b)
        return 1;
        if(p==0)
        return 1;
        else if(abs(p)%2==0)
        return 2;
        return -1;
    }
};