class Solution {
public:

    int res = 0;

    bool checkPal(string &s)
    {
        int start = 0;
        int end = s.size()-1;
        
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            
            start++;
            end--;
        }

        return true;
    }

    void helper(string &s, int idx, string &s1, string &s2)
    {
        if(idx == s.size())
        {
            if(checkPal(s1) && checkPal(s2))
            {
                int product = s1.length() * s2.length();
                res = max(res, product);
            }

            return;
        }

            s1.push_back(s[idx]);
            helper(s, idx+1, s1, s2);
            s1.pop_back();

            s2.push_back(s[idx]);
            helper(s, idx+1, s1, s2);
            s2.pop_back();

            helper(s, idx+1, s1, s2);
    }

    int maxProduct(string s) {
        string s1 = "";
        string s2 = "";

        helper(s, 0, s1, s2);
        return res;
    }
};
