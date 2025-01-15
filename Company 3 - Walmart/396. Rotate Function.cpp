class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long int f = 0;
        long long int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            f += nums[i] * i;
            sum += nums[i];
        }

        long long maxi = f;
        for (int j=1; j<n; j++)
        {
            f = f + sum - (long long)n * nums[n - j];
            maxi = max(maxi, f);
        }

        return maxi;
    }
};
