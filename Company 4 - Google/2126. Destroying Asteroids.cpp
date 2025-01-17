class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long int gain = mass;

        for(int i=0; i<asteroids.size(); i++)
        {
            if(gain >= asteroids[i])
                gain += asteroids[i];
            else
                return false;
        }

        return true;
    }
};
