class Solution {
public:

    map<vector<int>, int> m;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(m.count(needs) != 0)
            return m[needs];
        
        int res = 0;

        for(int i=0; i<needs.size(); i++)
            res += needs[i]*price[i];
        
        for(int i=0; i<special.size(); i++)
        {
            bool valid = true;

            for(int j=0; j<needs.size(); j++)
            {
                if(needs[j]<special[i][j])
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
            {
                for(int j=0; j<needs.size(); j++)
                    needs[j] -= special[i][j];

                int tempRes = special[i].back() + shoppingOffers(price, special, needs);
                res = min(res, tempRes);

                for(int j=0; j<needs.size(); j++)
                    needs[j] += special[i][j];
            }
        }

        return m[needs]=res;
    }
};
