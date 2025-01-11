class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        int res = 0;

        while(i<nums.size() && j<nums.size())
        {
            if(nums[j] - nums[i] > k)
                i++;
            else if(i == j || nums[j] - nums[i] < k)
                j++;
            else
            {
                res++;
                i++;
                j++;

                while(j<nums.size() && nums[j] == nums[j-1])
                    j++;
                
                while (i < nums.size() && nums[i] == nums[i - 1])
                    i++;
            }
        }

        return res;
    }
};
