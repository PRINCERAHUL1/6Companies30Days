class Solution {
public:

    void helper(int idx, int s, int n,vector<vector<int>> &res, vector<int> &temp, int k)
    {
        if(s==n && k==0)
        {
            res.push_back(temp);
            return;
        }

        if(s>n)
            return;
        
        for(int i=idx; i<=9; i++)
        {
            if(i>n)
                break;
            
            temp.push_back(i);
            helper(i+1, s+i, n, res, temp, k-1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(1, 0, n, res, temp, k);

        return res;
    }
};
