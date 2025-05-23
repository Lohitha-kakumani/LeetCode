class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;  

                            if (solve(board)) {
                                return true;  
                            }

                            board[i][j] = '.';  
                        }
                    }
                    return false; 
                }
            }
        }
        return true;  
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
            if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num) {
                return false;
            }
        }
        return true;
    }
};