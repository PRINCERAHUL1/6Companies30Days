class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;
        int res = 0;

        for (string word : startWords) 
        {
            sort(word.begin(), word.end());
            s.insert(word);
        }

        for (string trial : targetWords) 
        {
            sort(trial.begin(), trial.end());
            bool flag = false;

            for (int j = 0; j < trial.size(); j++) 
            {
                string search = trial.substr(0, j) + trial.substr(j + 1);

                if (s.find(search) != s.end())
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
                res++;
        }

        return res;
    }
};

