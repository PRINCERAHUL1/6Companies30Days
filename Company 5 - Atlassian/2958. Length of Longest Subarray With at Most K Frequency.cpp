class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = 1;
        map<int, int> m;
        m[nums[0]] = 1;
        int j = 0;

        for(int i=1; i<nums.size(); i++)
        {
            if(m[nums[i]]+1 <= k)
            {
                m[nums[i]]++;
                maxi = max(maxi, i-j+1);
            }
            else
            {
                while(m[nums[i]]+1 > k)
                {
                    m[nums[j]]--;
                    j++;
                }

                m[nums[i]]++;
            }
        }

        return maxi;
    }
};
