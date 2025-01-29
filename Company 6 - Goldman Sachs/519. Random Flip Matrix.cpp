class Solution {
public:

    unordered_map<int,int> V;
    int nr, nc, rem;
    mt19937 rng{random_device{}()};
    
    int randint(int bound)
    {
        uniform_int_distribution<int> uni(0, bound);
        return uni(rng);
    }

    Solution(int m, int n) {
        nr = m, nc = n, rem = nr * nc;
    }
    
    vector<int> flip() {
        int r = randint(--rem);
        int x = V.count(r) ? V[r] : V[r] = r;
        V[r] = V.count(rem) ? V[rem] : V[rem] = rem;
        return {x / nc, x % nc};
    }
    
    void reset() {
        V.clear();
        rem = nr*nc;
    }
};
