class Solution {
  public:
    string encode(string s) {
        string dest = "";
    
        for(int i = 0; i < s.size(); i++)
        {
            dest += s[i];
            int count = 1;
            
            while(i+1 < s.size() and s[i] == s[i+1])
            {
                count++;
                i++;
            }
    
            dest += to_string(count);
        }
    
        return dest;
    }
};
