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
    vector<vector<bool>> row = vector<vector<bool>>(9, vector<bool>(10, false));  // ��¼��ǰ���Ƿ������֣�row[i][j] ��i���Ƿ�������j
    vector<vector<bool>> column = vector<vector<bool>>(9, vector<bool>(10, false));  // ��¼��ǰ���Ƿ������֣�column[i][j] ��i���Ƿ�������j
    vector<vector<vector<bool>>> grid = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));  // ��¼��ǰ�����Ƿ������飬grid[i][j][k]����¼��ihang��j�����С�����Ƿ�������k

    bool __solveSudoku(vector<vector<char>>& board, int count) {
        if (count == 0)
            return true;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.')
                    continue;
                for (char k = '1'; k <= '9'; ++k) {
                    int num = k - '0';  // �����num����������0-8   ��������1-9
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
                return false;  // ���1-9���Թ����У�˵���ϸ�λ�õ����ֲ��У���Ҫ���¸��� ֱ�ӷ���
            }
        }
        return true;
    }

};

int main() {

	system("pause");
	return 0;
}