class Solution {
public:
    long long power(long long x, long long y, long long mod)
{
    long long ans = 1;

    while(y > 0)
    {
        if(y & 1)
            ans = (ans * x) % mod;

        x = (x * x) % mod;
        y /= 2;
    }

    return ans;
}
    int sumDecoded(vector<long long>& nums) {
        long long n=nums.size();
        long long sum=0;
        long long mod=1000000007;
        for(int i=0;i<n;i++)
        {
            long long a=nums[i];
            long long width=a%10;
            long long d=floor(nums[i]/10);
            long long x=0;
            long long y=0;
            long long j=0;
            long long q=d;
            while(q>0)
            {
                j++;
                q/=10;
            }
            int k=0;
            while(j-width>0)
            {
                y+=(d%10)*pow(10,k++);
                d/=10;
                j--;
            }
            x=d;
            sum = (sum + power(x,y,mod)) % mod;
        }
        return (int)sum;
    }
};