class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(nums);
        sort(v.begin(), v.end());
        
        int i = n-1;
        int j = 0;
        int k = i/2 +1;

        while(i >= 0)
        {
            if(i%2 == 0)
            {
                nums[i] = v[j];
                j++;
            }
            else
            {
                nums[i] = v[k];
                k++;
            }

            i--;
        }
        
    }
};
