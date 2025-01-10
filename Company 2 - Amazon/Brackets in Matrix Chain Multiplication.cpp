class Solution {
  public:
  
    pair<string, int> helper(vector<int> &arr, int i, int j, vector<vector<pair<string, int>>> &v)
    {
        if(i == j)
        {
            string st = "";
            st += 'A'+i-1;
            
            return {st, 0};
        }
        
        if(v[i][j].second != -1)
            return v[i][j];
        
        int m = INT_MAX;
        string s = "";
        
        for(int k=i; k<j; k++)
        {
            auto left = helper(arr, i, k, v);
            auto right = helper(arr, k+1, j, v);
            int x = left.second + right.second + arr[i-1]*arr[k]*arr[j];
            string sr = "("+left.first+right.first+")";
            
            if(m>x)
            {
                m = x;
                s = sr;
            }
        }
        
        v[i][j] = {s, m};
        return v[i][j];
    }
    
    string matrixChainOrder(vector<int> &arr) {
        vector<vector<pair<string, int>>> v(arr.size(), vector<pair<string, int>>(arr.size(), {"", -1}));
        auto res = helper(arr, 1, arr.size()-1, v);
        
        return res.first;
    }
};
