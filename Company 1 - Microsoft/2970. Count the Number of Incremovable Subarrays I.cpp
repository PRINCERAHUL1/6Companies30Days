class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                bool check = true;
                int last = INT_MIN;

                for(int k=0; k<n; k++)
                {
                    if(k>=i && k<=j)
                        continue;
                    
                    if(last >= nums[k])
                    {
                        check = false;
                        break;
                    }

                    last = nums[k];
                }

                if(check)
                    count++;
                
            }
        }

        return count;
    }
};
