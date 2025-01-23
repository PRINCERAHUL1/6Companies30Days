class Solution {
public:
    int countCollisions(string directions) {
        int d = directions.size();
        vector<pair<char, int>> v;
        int res = 0;

        for(int i=0; i<d; i++)
        {
            int count = 1;
            while(i+1<d && directions[i] == directions[i+1])
            {
                count++;
                i++;
            }

            v.push_back({directions[i], count});
        }

        for(int i=0; i<v.size()-1; i++)
        {
            if(v[i].first == 'R' && v[i+1].first == 'L')
                res += v[i].second + v[i+1].second;
            else if(v[i].first == 'S' && v[i+1].first == 'L')
                res += v[i+1].second;
            else if(v[i].first == 'R' && v[i+1].first == 'S')
                res += v[i].second;
        }

        return res;
    }
};
