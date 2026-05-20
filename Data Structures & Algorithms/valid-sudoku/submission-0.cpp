class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9);
        vector<set<int>> cols(9);
        vector<set<int>> boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if (cur != '.') {
                    int box = (int)j/3 + ((int)i/3)*3;
                    if (rows[i].count(cur) || cols[j].count(cur) || boxes[box].count(cur)) {
                        return false;
                    }
                    rows[i].insert(cur);
                    cols[j].insert(cur);
                    boxes[box].insert(cur);
                }
            }
        }
        return true;

    }
};
