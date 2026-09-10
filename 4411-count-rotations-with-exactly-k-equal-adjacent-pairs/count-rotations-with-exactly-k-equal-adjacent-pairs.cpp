class Solution {
public:
    int countRotations(string s, int k) {
        int p=0;
        int n=s.size();
        int i=0;
        while(i<n)
        {
            int j=i;
            int c=0;
            while(j<i+n)
            {
                if(s[j]==s[j+1])
                c++;
                j++;
            }
            if(c==k)
            p++;
            s.push_back(s[i]);
            i++;
        }
        return p;
    }
};