class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long res = 0;
        int i=0;
        unordered_set<int> s;

        for(int j=0; j<nums.size(); j++)
        {
            while(i<j && (s.count(nums[j]) || k <= s.size()) )
            {
                sum -= nums[i];
                s.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            s.insert(nums[j]);

            if(k == s.size())
                res = max(res, sum);
        }

        return res;
    }
};
