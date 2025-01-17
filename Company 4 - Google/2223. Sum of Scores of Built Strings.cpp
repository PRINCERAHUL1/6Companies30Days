class Solution {
public:

    long long helper(vector<int> &v, string s)
    {
        int l = 0;
        int r = 0;
        long long res = 0;

        for(int i=1; i<s.length(); i++)
        {
            if(i>r)
            {
                l=r=i;
                
                while(r<s.length() && s[r] == s[r-l])
                    r++;
                
                v[i] = r-l;
                r--;
            }
            else
            {
                int k = i-l;

                if(v[k]+i > r)
                {
                    l=i;

                    while(r<s.length() && s[r] == s[r-l])
                        r++;
                    
                    v[i] = r-l;
                    r--;
                }
                else
                    v[i] = v[k];
            }

            res += v[i];
        }

        return res+s.length();
    }

    long long sumScores(string s) {
        vector<int> v(s.length(), 0);

        return helper(v, s);
    }
};
