class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> m;
        if(s.size()<10)
            return res;

        for(int i=0; i<s.size(); i++)
        {
            string temp = s.substr(i, 10);
            m[temp]++;
        }

        for(auto it: m)
        {
            if(it.second > 1)
                res.push_back(it.first);
        }

        return res;
    }
};
