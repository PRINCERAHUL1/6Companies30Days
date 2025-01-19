class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<nums.size(); i++)
            pq.push(nums[i]);
        
        while(k--)
        {
            int x = pq.top();
            pq.pop();
            x++;
            pq.push(x);
        }

        long long mod = 1e9+7;
        long long res = 1;

        while(!pq.empty())
        {
            res = (res*pq.top())%mod;
            pq.pop();
        }

        return res;
    }
};
