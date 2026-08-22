// https://leetcode.cn/problems/n-queens/description/


class Solution
{
public:
    vector<bool> checkcol;                         // 标记每一列是否已经放置皇后
    vector<vector<string>> ret;                    // 保存所有满足条件的棋盘方案
    vector<string> path;                           // 保存当前正在构造的棋盘
    vector<bool> checkdig1;                        // 标记主对角线是否已有皇后
    vector<bool> checkdig2;                        // 标记副对角线是否已有皇后
    int n = 0;                                     // 保存棋盘大小

    void dfs(int row)                              // 按行递归放置皇后
    {
        if (row == n)                               // 所有行都成功放置皇后
        {
            ret.push_back(path);                   // 保存当前棋盘方案
            return;                                // 当前搜索结束
        }

        for (int col = 0; col < n; col++)           // 枚举当前行所有可能的列
        {
            if (!checkcol[col] && !checkdig1[row - col + n] && !checkdig2[row + col]) // 判断当前位置是否安全
            {
                path[row][col] = 'Q';              // 在当前位置放置皇后
                checkcol[col] = checkdig1[row - col + n] = checkdig2[row + col] = true; // 标记列和两条对角线被占用
                dfs(row + 1);                      // 递归处理下一行皇后放置
                path[row][col] = '.';              // 回溯撤销当前位置的皇后
                checkcol[col] = checkdig1[row - col + n] = checkdig2[row + col] = false; // 恢复列和对角线状态
            }
        }
    }

    vector<vector<string>> solveNQueens(int _n)
    {
        n = _n;                                    // 保存输入的棋盘大小
        checkcol.resize(n);                        // 初始化列检查数组
        checkdig1.resize(2 * n);                   // 初始化主对角线检查数组
        checkdig2.resize(2 * n);                   // 初始化副对角线检查数组
        path.resize(n);                            // 创建n行棋盘
        for (int i = 0; i < n; i++)                 // 初始化每一行为空棋盘
            path[i].append(n, '.');                // 将当前行全部填充为'.'
        dfs(0);                                    // 从第0行开始放置皇后
        return ret;                                // 返回所有合法方案
    }
};