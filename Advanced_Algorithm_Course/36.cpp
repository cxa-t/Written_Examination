// https://leetcode.cn/problems/valid-sudoku/


class Solution
{
    bool row[9][10];                                  // 记录每一行中数字1-9是否已经出现
    bool col[9][10];                                  // 记录每一列中数字1-9是否已经出现
    bool grid[3][3][10];                              // 记录每个3×3宫格中数字1-9是否已经出现

public:
    bool isValidSudoku(vector<vector<char>>& board)   // 判断当前数独是否合法
    {
        for (int i = 0; i < 9; i++)                   // 遍历数独的每一行
        {
            for (int j = 0; j < 9; j++)              // 遍历当前行的每一列
            {
                if (board[i][j] != '.')                // 跳过空白位置
                {
                    int num = board[i][j] - '0';      // 将字符数字转换为整数
                    if (row[i][num] || col[j][num] || grid[i / 3][j / 3][num]) // 判断当前数字是否在行列宫格中重复
                        return false;                 // 存在重复数字则数独非法

                    row[i][num] = true;               // 标记当前数字已经出现在该行
                    col[j][num] = true;               // 标记当前数字已经出现在该列
                    grid[i / 3][j / 3][num] = true;   // 标记当前数字已经出现在该3×3宫格
                }
            }
        }
        return true;                                  // 所有位置检查通过则数独合法
    }
};