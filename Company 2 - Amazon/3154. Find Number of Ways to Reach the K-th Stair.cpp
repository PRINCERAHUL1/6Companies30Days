class Solution {
public:
    int f[32][32];
    
    int helper(int a, int b)
    {
        if(a==b || b==0)
            return 1;
        
        if(f[a][b] > 0)
            return f[a][b];
        
        int res = helper(a-1, b-1) + helper(a-1, b);
        f[a][b] = res;

        return res;
    }

    int waysToReachStair(int k) {
        memset(f, 0, sizeof f);
        int res = 0;
        int sum = 1;

        for(int i=0; i<30; i++)
        {
            int d = sum-k;
            if(d>=0 && d<=i+1)
                res += helper(i+1, d);
            
            sum += int(pow(2, i));
        }

        return res;
    }
};
