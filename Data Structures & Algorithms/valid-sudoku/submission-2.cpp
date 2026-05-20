// Bit Masking technique from claude
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> boxes(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if (cur == '.') continue;
                int c = cur - '0';
                int bit = 1 << c;
                int box = (j / 3) + (i / 3) * 3;
                cout << box << endl;
                if (rows[i] & bit || cols[j] & bit || boxes[box] & bit) return false;
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit;
            }
        }
        return true;
    }
};
