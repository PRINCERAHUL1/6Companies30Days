class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> res;
        vector<int> va;
        vector<int> vb;

        if (a.size() > s.size() || b.size() > s.size())
            return res;

        for(int i=0; i<=(s.size() - a.size()); i++)
        {
            if(s.substr(i, a.size()) == a)
                va.push_back(i);
        }

        for(int j=0; j<=(s.size() - b.size()); j++)
        {
            if(s.substr(j, b.size()) == b)
                vb.push_back(j);
        }

        for(int i=0; i<va.size(); i++)
        {
            for(int j=0; j<vb.size(); j++)
            {
                if(abs(va[i] - vb[j]) <= k)
                {
                    res.push_back(va[i]);
                    break;
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};
