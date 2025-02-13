class Solution {
public:

    int res = 0;

    vector<int> helper(TreeNode* node)
    {
        if(!node)
            return {INT_MAX, INT_MIN, 0};
        
        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);

        if(left[1] >= node->val || right[0] <= node->val)
            return {INT_MIN, INT_MAX, 0};
        
        int sum = left[2] + right[2] + node->val;
        res = max(res, sum);

        return {min(node->val, left[0]), max(right[1], node->val), sum};
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return res;
    }
};
