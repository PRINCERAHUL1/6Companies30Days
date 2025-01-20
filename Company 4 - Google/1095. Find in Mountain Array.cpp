class Solution {
public:

    int peak(MountainArray &mountainArr, int n)
    {
        int start=0;
        int end = n-1;

        while(start<end)
        {
            int mid = start + (end-start)/2;

            if(mountainArr.get(mid+1) > mountainArr.get(mid))
            {
                start = mid+1;
            }
            else
                end = mid;
        }

        return start;
    }

    int bs(int s, int e, MountainArray &mountainArr, int target, bool flag)
    {
        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(target == mountainArr.get(mid))
            {
                return mid;
            }
            else if(target >mountainArr.get(mid))
            {
                if(flag)
                    e = mid-1;
                else
                    s = mid+1;
            }
            else
            {
                if(flag)
                    s = mid+1;
                else
                    e = mid-1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        if(n<3)
            return -1;
        
        int part = peak(mountainArr, n);

        int l = bs(0, part, mountainArr, target, 0);
        
        if(l != -1)
            return l;
        
        int r = bs(part+1, n-1, mountainArr, target, 1);

        return r;
    }
};
