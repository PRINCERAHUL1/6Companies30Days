class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int j = 0;
        int res = 0;
        int cost = 0;

        for(int i=0; i<s.size(); i++)
        {
            cost += abs(s[i]-t[i]);

            while(cost > maxCost)
            {
                cost -= abs(s[j]-t[j]);
                j++;
            }

            res = max(res, i-j+1);
        }

        return res;
    }
};
