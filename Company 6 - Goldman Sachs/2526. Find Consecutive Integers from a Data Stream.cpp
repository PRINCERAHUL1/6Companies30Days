class DataStream {
public:

    long long int val;
    long long int kk;
    long long int count = 0;

    DataStream(int value, int k) {
        val = value;
        kk = k;
    }
    
    bool consec(int num) {
        if(num == val)
        {
            count++;

            if(count >= kk)
                return true;
        }
        else if(num != val && count != 0)
            count = 0;
        
        return false;
    }
};

