class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            if (a[0] == b[0]) 
                return a[1] > b[1];
            
            return a[0] < b[0];
        });

        vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        vector<int> v;
        for (int h : heights) {
            auto it = lower_bound(v.begin(), v.end(), h);
            if (it == v.end()) {
                v.push_back(h);
            } 
            else
                *it = h;
        }

        return v.size();
    }
};
