class Solution {
public:

    int res = 0;
    vector<int> helper(TreeNode* root, int d)
    {
        if(!root)
            return {};
        
        if(!root->left && !root->right)
            return {1};
        
        vector<int> l = helper(root->left, d);
        vector<int> r = helper(root->right, d);
        vector<int> v;

        for(auto i: l)
        {
            for(auto j: r)
            {
                if(i+j <= d)
                    res++;
            }

            i++;
            if(i<d)
                v.push_back(i);
        }

        for(auto j: r)
        {
            j++;

            if(j<d)
                v.push_back(j);
        }

        return v;
    }

    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        return res;
    }
};
