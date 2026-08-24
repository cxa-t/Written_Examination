// https://leetcode.cn/problems/sudoku-solver/description/


class Solution
{
public:
    bool checkrow[9][10];                          // 标记每一行中数字1-9是否已经被使用
    bool checkcol[9][10];                          // 标记每一列中数字1-9是否已经被使用
    bool checkblock[3][3][10];                     // 标记每个九宫格中数字1-9是否已经被使用

    void solveSudoku(vector<vector<char>>& board)  // 求解数独并修改原棋盘结果
    {
        for (int i = 0; i < 9; i++)                 // 遍历棋盘所有行
        {
            for (int j = 0; j < 9; j++)             // 遍历棋盘所有列
            {
                if (board[i][j] != '.')              // 初始化已有数字的占用状态
                {
                    int num = board[i][j] - '0';   // 将字符数字转换为整数
                    checkrow[i][num] = true;       // 标记该数字已经存在于当前行
                    checkcol[j][num] = true;       // 标记该数字已经存在于当前列
                    checkblock[i / 3][j / 3][num] = true; // 标记该数字已经存在于当前九宫格
                }
            }
        }
        dfs(board);                                // 从第一个空格开始尝试填充
    }

    bool dfs(vector<vector<char>>& board)          // 递归搜索当前数独是否存在合法解
    {
        for (int i = 0; i < 9; i++)                 // 查找当前棋盘中的空格位置
        {
            for (int j = 0; j < 9; j++)             // 继续遍历每一列寻找空格
            {
                if (board[i][j] == '.')              // 找到一个需要填充的空位置
                {
                    for (int num = 1; num <= 9; num++) // 枚举该位置可以填写的数字
                    {
                        if (!checkrow[i][num] && !checkcol[j][num] && !checkblock[i / 3][j / 3][num]) // 判断数字是否满足数独规则
                        {
                            board[i][j] = num + '0'; // 尝试将合法数字填入当前位置
                            checkrow[i][num] = true; // 标记当前行已经使用该数字
                            checkcol[j][num] = true; // 标记当前列已经使用该数字
                            checkblock[i / 3][j / 3][num] = true; // 标记当前九宫格已经使用该数字

                            if (dfs(board)) return true; // 如果后续位置全部填充成功，向上返回成功

                            board[i][j] = '.';          // 当前选择失败，恢复当前位置为空
                            checkrow[i][num] = false;  // 撤销当前行数字占用状态
                            checkcol[j][num] = false;  // 撤销当前列数字占用状态
                            checkblock[i / 3][j / 3][num] = false; // 撤销当前九宫格数字占用状态
                        }
                    }
                    return false;                     // 当前空格所有数字均无法成功，通知上一层回溯
                }
            }
        }
        return true;                                  // 遍历不到空格，说明整个数独已经完成
    }
};