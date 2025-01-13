class Solution {
public:

    static bool cmp(pair<string, int> &a, pair<string, int> &b)
    {
        if(a.second == b.second)
            return a.first<b.first;

        return a.second>b.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;

        for(auto word: words)
            m[word]++;
        
        vector<pair<string, int>> temp;

        for(auto it: m)
            temp.push_back(it);
        
        sort(temp.begin(), temp.end(), cmp);

        for(int i=0; i<k; i++)
            res.push_back(temp[i].first);
        
        return res;
    }
};
