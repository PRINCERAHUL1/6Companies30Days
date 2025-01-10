class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> res;
        map<string, int> m;
        
        for(int i=0; i<n; i++)
            m[contact[i]]++;
        
        for(int i=0; i<s.size(); i++)
        {
            vector<string> v;
            
            for(auto it: m)
            {
                if(it.first.substr(0, i+1) == s.substr(0, i+1))
                    v.push_back(it.first);
            }
            
            if(v.size() == 0)
                v.push_back("0");
            
            res.push_back(v);
        }
        
        return res;
    }
};
