class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int res = 0;

        for(int i=1; i<=n-2;)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                int j = i;
                int count = 1;

                while(j>0 && arr[j]>arr[j-1])
                {
                    j--;
                    count++;
                }

                while(i<n-1 && arr[i]>arr[i+1])
                {
                    i++;
                    count++;
                }

                res = max(res, count);
            }
            else
                i++;
            
        }

        return res;
    }
};
