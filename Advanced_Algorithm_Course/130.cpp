// https://leetcode.cn/problems/surrounded-regions/


class Solution
{
public:
    int m = 0;                                      // 保存棋盘的行数
    int n = 0;                                      // 保存棋盘的列数
    vector<vector<bool>> vis;                       // 标记与边界连通的'O'位置
    int dx[4] = { -1, 1, 0, 0 };                     // 定义上下四个方向的行偏移
    int dy[4] = { 0, 0, -1, 1 };                     // 定义左右四个方向的列偏移
    void dfs(vector<vector<char>>& board, int i, int j) // 标记与当前边界'O'连通的所有'O'
    {
        vis[i][j] = true;                           // 标记当前位置不能被围绕
        for (int k = 0; k < 4; k++)                  // 枚举上下左右四个方向
        {
            int x = dx[k] + i;                      // 计算相邻位置的行坐标
            int y = dy[k] + j;                      // 计算相邻位置的列坐标
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && board[x][y] == 'O') // 判断相邻位置是否为未访问的'O'
            {
                dfs(board, x, y);                   // 继续标记与边界连通的'O'
            }
        }
    }
    void solve(vector<vector<char>>& board)         // 将所有被'X'完全包围的'O'修改为'X'
    {
        m = board.size();                           // 获取棋盘的行数
        n = board[0].size();                        // 获取棋盘的列数
        vis.resize(m, vector<bool>(n, false));      // 初始化所有位置为未访问状态
        for (int j = 0; j < n; j++)                  // 遍历棋盘的上下两条边界
        {
            if (board[0][j] == 'O' && !vis[0][j])    // 判断上边界当前位置是否为未访问的'O'
                dfs(board, 0, j);                   // 标记与上边界连通的所有'O'
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) // 判断下边界当前位置是否为未访问的'O'
                dfs(board, m - 1, j);                 // 标记与下边界连通的所有'O'
        }
        for (int i = 1; i < m - 1; i++)              // 遍历棋盘的左右两条边界
        {
            if (board[i][0] == 'O' && !vis[i][0])    // 判断左边界当前位置是否为未访问的'O'
                dfs(board, i, 0);                   // 标记与左边界连通的所有'O'
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) // 判断右边界当前位置是否为未访问的'O'
                dfs(board, i, n - 1);                 // 标记与右边界连通的所有'O'
        }
        for (int i = 0; i < m; i++)                  // 遍历棋盘中的每一行
        {
            for (int j = 0; j < n; j++)              // 遍历当前行中的每一列
            {
                if (board[i][j] == 'O' && vis[i][j] == false) // 找到没有与边界连通的'O'
                    board[i][j] = 'X';              // 将被包围的'O'修改为'X'
            }
        }
    }
};