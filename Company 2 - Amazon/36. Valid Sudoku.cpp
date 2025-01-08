class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCase[9][9] = {0};
        int colCase[9][9] = {0};
        int gridCase[9][9] = {0};

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';

                    int k = (i/3) *3 + j/3;

                    if(rowCase[i][num-1]++ || colCase[j][num-1]++ || gridCase[k][num-1]++)
                        return false;
                }
            }
        }

        return true;
    }
};
