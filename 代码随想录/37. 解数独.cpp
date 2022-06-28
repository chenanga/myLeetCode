#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    column[j][num] = true;
                    grid[i / 3][j / 3][num] = true;
                }
                else
                    count++;
            }
        }
        __solveSudoku(board, count);
        return;
    }

private:
    vector<vector<bool>> row = vector<vector<bool>>(9, vector<bool>(10, false));  // 记录当前行是否有数字，row[i][j] 第i行是否有数字j
    vector<vector<bool>> column = vector<vector<bool>>(9, vector<bool>(10, false));  // 记录当前行是否有数字，column[i][j] 第i行是否有数字j
    vector<vector<vector<bool>>> grid = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));  // 记录当前格子是否有数组，grid[i][j][k]，记录第ihang第j列这个小格子是否有数字k

    bool __solveSudoku(vector<vector<char>>& board, int count) {
        if (count == 0)
            return true;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.')
                    continue;
                for (char k = '1'; k <= '9'; ++k) {
                    int num = k - '0';  // 这里的num是索引，从0-8   代表数字1-9
                    if (row[i][num] || column[j][num] || grid[i / 3][j / 3][num])
                        continue;
                    row[i][num] = true;
                    column[j][num] = true;
                    grid[i / 3][j / 3][num] = true;
                    board[i][j] = k;

                    if (__solveSudoku(board, count - 1))
                        return true;

                    board[i][j] = '.';
                    row[i][num] = false;
                    column[j][num] = false;
                    grid[i / 3][j / 3][num] = false;
                }
                return false;  // 如果1-9都试过不行，说明上个位置的数字不行，需要重新更换 直接返回
            }
        }
        return true;
    }

};

int main() {

	system("pause");
	return 0;
}