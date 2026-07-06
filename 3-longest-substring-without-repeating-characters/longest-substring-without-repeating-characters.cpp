class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int mm=0;
        unordered_map<char,int>m;
        while(j<n)
        {
            if(m.find(s[j])!=m.end())
            {
                auto it=m.find(s[j]);
                if(i<=it->second)
                {
                i=it->second+1;
                }
            }
            mm=max(mm,j-i+1);
            m[s[j]]=j;
            j++;
        }
        return mm;
    }
};