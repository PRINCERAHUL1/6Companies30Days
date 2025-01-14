class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        string res = "";
        priority_queue<pair<int, char>> pq;

        for(int i=0; i<s.size(); i++)
            m[s[i]]++;
        
        for(auto i: m)
            pq.push({i.second, i.first});
        
        while(!pq.empty())
        {
            int n = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            while(n--)
                res += c;
        }

        return res;
    }
};
