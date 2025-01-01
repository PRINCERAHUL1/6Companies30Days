class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        int start = 0;

        for(int i=1; i<=n; i++)
            v.push_back(i);
        
        while(v.size() > 1)
        {
            int remove = (start + k-1)%v.size();

            v.erase(v.begin() + remove);

            start = remove;
        }

        return v.front();
    }
};
