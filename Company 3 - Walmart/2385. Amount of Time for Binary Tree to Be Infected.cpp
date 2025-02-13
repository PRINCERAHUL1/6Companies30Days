class Solution {
public:

    int res;

    void buildGraph(TreeNode* root, vector<vector<int>> &adj)
    {
        if(root == NULL)
            return ;
        
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }

        buildGraph(root->left, adj);
        buildGraph(root->right, adj);
    }

    void bfs(int start, vector<vector<int>> &adj, vector<bool> &vis)
    {
        queue<int> q;

        q.push(start);

        while(!q.empty())
        {
            int k = q.size();

            while(k--)
            {
                int u = q.front();
                q.pop();
                vis[u] = 1;

                for(int i=0; i<adj[u].size(); i++)
                {
                    if(!vis[adj[u][i]])
                        q.push(adj[u][i]);
                }
            }

            res++;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(100001);
        vector<bool> vis(100001);

        buildGraph(root, adj);
        res = 0;
        bfs(start, adj, vis);

        return res-1;
    }
};
