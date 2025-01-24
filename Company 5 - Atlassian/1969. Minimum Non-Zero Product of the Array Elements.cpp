class Solution {
public:

    #define mod 1000000007
    int power(long long a, long long b)
    {
        int res = 1;
        a = a%mod;

        if(a == 0)
            return 0;
        
        while(b>0)
        {
            if(b&1)
                res = (res*a)%mod;
            
            b = b/2;
            a = (a*a)%mod;
        }

        return res;
    }

    int minNonZeroProduct(int p) {
        if(p==1)
            return 1;
        
        long long val = (1L<<p)-1;
        return (val%mod*power(val-1, val/2)%mod)%mod;
    }
};
