// https://leetcode.cn/problems/minesweeper/

class Solution
{
public:
    int m = 0;                                      // 保存棋盘的行数
    int n = 0;                                      // 保存棋盘的列数
    int dx[8] = { 0,0,-1,-1,-1,1,1,1 };             // 定义周围8个方向的行偏移
    int dy[8] = { -1,1,-1,0,1,-1,0,1 };             // 定义周围8个方向的列偏移
    void dfs(vector<vector<char>>& board, int i, int j) // 从当前位置递归展开扫雷区域
    {
        int count = 0;                              // 统计当前位置周围地雷数量
        for (int k = 0; k < 8; k++)                  // 遍历当前位置周围8个方向
        {
            int x = i + dx[k];                      // 计算相邻位置的行坐标
            int y = j + dy[k];                      // 计算相邻位置的列坐标
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') // 判断相邻位置是否为地雷
                count++;                            // 周围地雷数量加一
        }
        if (count)                                   // 周围存在至少一个地雷
        {
            board[i][j] = count + '0';              // 将当前位置显示为周围地雷数量
            return;                                 // 当前格子无需继续向外展开
        }
        else                                        // 周围不存在地雷
        {
            board[i][j] = 'B';                      // 将当前位置标记为空白区域
            for (int k = 0; k < 8; k++)              // 遍历当前位置周围8个方向
            {
                int x = i + dx[k];                  // 计算相邻位置的行坐标
                int y = j + dy[k];                  // 计算相邻位置的列坐标
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E') // 判断相邻位置是否为未揭开的空格
                    dfs(board, x, y);               // 继续递归展开相邻空格
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) // 根据点击位置更新扫雷棋盘
    {
        m = board.size();                            // 获取棋盘的行数
        n = board[0].size();                         // 获取棋盘的列数
        if (board[click[0]][click[1]] == 'M')         // 判断点击位置是否直接踩到地雷
        {
            board[click[0]][click[1]] = 'X';        // 将被点击的地雷标记为爆炸
            return board;                           // 踩雷后直接返回棋盘
        }
        dfs(board, click[0], click[1]);             // 从点击位置开始递归展开区域
        return board;                               // 返回更新后的棋盘
    }
};