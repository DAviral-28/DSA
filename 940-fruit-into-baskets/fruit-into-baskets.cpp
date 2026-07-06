class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0,j=0;
        int m=1;
        unordered_map<int,int>mm;
        while(j<n)
        {
            mm[fruits[j]]=j;
            if(mm.size()>2)
            {
                int a=mm.begin()->second;
                int b=mm.begin()->first;
                for(auto it=mm.begin();it!=mm.end();it++)
                {
                    if(it->second<a)
                    {
                        a=it->second;
                        b=it->first;
                    }
                }
                mm.erase(b);
                i=a+1;
            }
            m=max(m,j-i+1);
            j++;
        }
        return m;
    }
};