class Solution {
public:
    int MOD=1000000007;
    long long power(long long a, long long b)
{
    if(b == 0)
        return 1;

    long long half = power(a, b / 2);

    half = (half * half) % MOD;

    if(b % 2)
        return (half * a) % MOD;

    return half;
}
    int countGoodNumbers(long long n) {
        long long even=ceil((double)n/2);
        long long odd=floor((double)n/2);
        long long mod=1e9+7;
        return (int)((power(4,odd)%mod)*power(5,even)%mod)%mod;
    }
};