class Codec {
public:

    void serDfs(TreeNode* root, string &s)
    {
        if(root == NULL)
        {
            s.append(",#");
            return;
        }

        s.append(",");
        s.append(to_string(root->val));

        serDfs(root->left, s);
        serDfs(root->right, s);
    }

    TreeNode* deserDfs(string &s, int &i)
    {
        i++;
        string n;

        while(i<s.size() && s[i] != ',')
        {
            n += s[i];
            i++;
        }

        if(n == "#")
            return NULL;
        
        TreeNode* node = new TreeNode(stoi(n));

        node->left = deserDfs(s, i);
        node->right = deserDfs(s, i);

        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serDfs(root, s);

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        TreeNode* root= deserDfs(data, i);

        return root;
    }
};
