class Solution {
public:
    int candy(vector<int>& ratings) {
        //slope wala approach
        int n=ratings.size();
        int i=1;
        int sum=1;
        int peak=0;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                i++;
                sum++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1])
            {
                sum+=down;
                down++;  
                i++;
            }
            if(peak<down)
            sum+=down-peak;
        }
        return sum;
    }
};