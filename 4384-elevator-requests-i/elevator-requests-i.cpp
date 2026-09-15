class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int l=0;
        int s=0;
        int m=requests.size();
        for(int i=0;i<m;i++)
        {
            s=s+abs(requests[i]-l);
            l=requests[i];
        }
        return s;
    }
};