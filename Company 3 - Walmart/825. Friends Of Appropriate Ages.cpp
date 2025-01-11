class Solution {
public:

    bool request(int x, int y)
    {
        return !(y <= 0.5*x + 7 || y>x || (y>100 && x<100));
    }

    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> m;
        int res = 0;

        for(auto age: ages)
            m[age]++;
        
        for(auto x: m)
        {
            for(auto y: m)
            {
                if(request(x.first, y.first))
                    res += x.second* (y.second - (x.first == y.first ? 1 : 0));
            }
        }

        return res;
    }
};
