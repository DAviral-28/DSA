class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int five=0,ten=0,twenty=0;
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            five++;
            else if(bills[i]==10)
            {
                if(five<1)
                return false;
                five--;
                ten++;
            }
            else
            {
                if(ten>=1 && five>=1)
                {
                    ten--;
                    five--;
                }
                else if(five>=3)
                five=five-3;
                else
                return false;
                twenty++;
            }
        }
        return true;
    }
};