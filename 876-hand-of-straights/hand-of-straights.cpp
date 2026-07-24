class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
        return false;
        map<int,int>m;
        for(int i=0;i<hand.size();i++)
        m[hand[i]]++;
        auto it=m.begin();
        while(it!=m.end())
        {
            if(it->second==0)
            {
                it++;
                continue;
            }
            int s=it->first;
            int c=it->second;
            for(int i=0;i<groupSize;i++)
            {
                if(m[s+i]<c)
                return false;
                m[s+i]-=c;
            }
            it++;
        }
        return true;
    }
};