// Bit Masking technique from claude
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> boxes(9,0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if (cur != '.') {
                    int c = cur - '0';
                    int bit = 1 << cur;
                    int box = (int)j / 3 + ((int)i / 3) * 3;
                    if(rows[i] & bit || cols[j] & bit || boxes[box] & bit)
                        return false;
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[box] |= bit;
                }
            }
        }
        return true;
    }
};
