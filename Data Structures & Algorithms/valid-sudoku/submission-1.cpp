class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row{0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                else if(!row[board[i][j]]) row[board[i][j]]++;
                else return false;
            }
            unordered_map<char, int> col{0};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                else if(!col[board[j][i]]) col[board[j][i]]++;
                else return false;
            }
            unordered_map<char, int> square{0};
            for (int j = 0; j < 9; j++) {
                if (board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] == '.') continue;
                else if(!square[board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3]]) square[board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3]]++;
                else return false;
            }
        }
        return true;
    }
};
