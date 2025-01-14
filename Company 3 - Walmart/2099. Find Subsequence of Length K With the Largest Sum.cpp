class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
        vector<int> res;
        unordered_map<int, int> m;

        sort(nums.begin(), nums.end(), greater<int>());

        for(int i=0; i<k; i++)
            m[nums[i]]++;
        
        for(auto t: temp)
        {
            if(m[t]-- >0)
                res.push_back(t);
        }

        return res;
    }
};
