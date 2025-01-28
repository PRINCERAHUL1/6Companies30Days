class Solution{   
public:
    string res = "987654321";

    void solve(vector<int> &vis, string &s, int i, string &ans)
    {
        if (i == s.length()) 
        {
            if (res > ans)
                res = ans;
            
            return;
        }

        if (i == -1)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (vis[j] == 0)
                {
                    vis[j] = 1;
                    ans += j + '0';
                    solve(vis, s, i + 1, ans);
                    ans.pop_back();
                    vis[j] = 0;
                }
            }
        }
        else if (s[i] == 'D')
        {
            int t = ans[ans.length() - 1] - '0';
                
            for (int j = t - 1; j >= 1; j--)
            {
                if (vis[j] == 0) 
                {
                    vis[j] = 1;
                    ans += j + '0';
                    solve(vis, s, i + 1, ans);
                    ans.pop_back();
                    vis[j] = 0;
                }
            }
        }
        else 
        {
            int t = ans[ans.length() - 1] - '0';
                
            for (int j = t + 1; j <= 9; j++)
            {
                if (vis[j] == 0)
                {
                    vis[j] = 1;
                    ans += j + '0';
                    solve(vis, s, i + 1, ans);
                    ans.pop_back();
                    vis[j] = 0;
                }
            }
        }
    }

    string printMinNumberForPattern(string S)
    {
        string ans = "";
        vector<int> vis(10, 0);
        solve(vis, S, -1, ans);
        return res;
    }
};
