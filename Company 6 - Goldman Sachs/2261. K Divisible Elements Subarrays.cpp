class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        vector<int> curSub;

        for(int i=0; i<nums.size(); i++)
        {
            curSub.clear();
            int divisibleCount = 0;

            for(int j=i; j<nums.size(); j++)
            {
                curSub.push_back(nums[j]);

                if(nums[j]%p == 0)
                    divisibleCount++;
                
                if(divisibleCount <= k)
                    s.insert(curSub);
                else
                    break;
            }
        }

        return s.size();
    }
};
