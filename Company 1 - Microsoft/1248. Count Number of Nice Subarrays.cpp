class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int prefSum = 0;
        unordered_map<int, int> m;
        m[0] = 1;

        for(int i=0; i<n; i++)
        {
            prefSum += (nums[i]%2 == 1) ? 1:0;
            res += m[prefSum-k];
            m[prefSum]++;
        }

        return res;
    }
};
