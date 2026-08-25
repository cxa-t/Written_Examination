// https://leetcode.cn/problems/word-search/


class Solution
{
public:
    vector<vector<bool>> vis;                         // 标记二维网格中已经访问过的位置
    int m;                                             // 保存棋盘行数
    int n;                                             // 保存棋盘列数

    bool exist(vector<vector<char>>& board, string word) // 判断网格中是否存在目标单词路径
    {
        m = board.size();                              // 获取棋盘行数
        n = board[0].size();                           // 获取棋盘列数

        vis.resize(m, vector<bool>(n));                // 初始化访问标记数组

        for (int i = 0; i < m; i++)                     // 遍历棋盘所有行
        {
            for (int j = 0; j < n; j++)                 // 遍历棋盘所有列
            {
                if (board[i][j] == word[0])              // 找到与单词首字符匹配的位置
                {
                    vis[i][j] = true;                  // 标记当前位置已经使用

                    if (dfs(board, i, j, word, 1))      // 从下一个字符开始递归搜索路径
                        return true;                   // 找到完整路径直接返回成功

                    vis[i][j] = false;                 // 回溯恢复当前位置未访问状态
                }
            }
        }
        return false;                                  // 遍历所有起点仍未找到路径
    }

    int dx[4] = { 1, -1, 0, 0 };                         // 定义上下左右四个方向的横坐标变化
    int dy[4] = { 0, 0, -1, 1 };                         // 定义上下左右四个方向的纵坐标变化

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int pos) // 从当前位置继续匹配单词
    {
        if (pos == word.size())                        // 所有字符都已经匹配成功
            return true;                              // 返回成功

        for (int k = 0; k < 4; k++)                    // 枚举四个移动方向
        {
            int x = i + dx[k];                        // 计算下一位置的行坐标
            int y = j + dy[k];                        // 计算下一位置的列坐标

            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && board[x][y] == word[pos]) // 判断下一位置是否合法且字符匹配
            {
                vis[x][y] = true;                     // 标记当前位置已经访问

                if (dfs(board, x, y, word, pos + 1))   // 递归匹配下一个字符
                    return true;                      // 后续路径成功则向上传递成功

                vis[x][y] = false;                    // 当前路径失败，撤销访问状态
            }
        }

        return false;                                 // 四个方向均无法匹配，当前路径失败
    }
};