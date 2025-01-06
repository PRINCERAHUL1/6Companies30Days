class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        string s = "!#$%&*?@^";
        unordered_map<char, int> m;
        
        for (int i = 0; i < n; i++)
            m[nuts[i]]++;
        
        int j = 0;
    
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] > 0)
            {
                nuts[j] = s[i];
                bolts[j] = s[i];
                j++;
            }
        }
    }
};
