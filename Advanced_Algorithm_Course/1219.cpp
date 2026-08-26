// https://leetcode.cn/problems/path-with-maximum-gold/

class Solution
{
public:
    vector<vector<bool>> check;                         // 标记二维网格中已经访问过的位置
    int ret = 0;                                         // 保存当前找到的最大黄金数量
    int m = 0;                                           // 保存网格行数
    int n = 0;                                           // 保存网格列数

    int getMaximumGold(vector<vector<int>>& grid)        // 求网格中可以收集的最大黄金数量
    {
        m = grid.size();                                // 获取网格的行数
        n = grid[0].size();                              // 获取网格的列数

        check.resize(m, vector<bool>(n));                // 初始化访问状态数组

        for (int i = 0; i < m; i++)                       // 遍历网格所有行
        {
            for (int j = 0; j < n; j++)                   // 遍历网格所有列
            {
                if (grid[i][j] != 0 && !check[i][j])       // 从每个有黄金的位置开始搜索
                {
                    check[i][j] = true;                  // 标记当前黄金位置已经访问
                    dfs(grid, i, j, grid[i][j]);         // 从当前位置开始深度搜索所有路径
                    check[i][j] = false;                 // 回溯恢复当前位置未访问状态
                }
            }
        }

        return ret;                                      // 返回搜索得到的最大黄金数量
    }

    int dx[4] = { -1, 1, 0, 0 };                           // 定义上下左右四个方向的行变化
    int dy[4] = { 0, 0, -1, 1 };                           // 定义上下左右四个方向的列变化

    void dfs(vector<vector<int>>& grid, int i, int j, int path) // 从当前位置继续搜索可收集黄金路径
    {
        ret = max(path, ret);                             // 更新当前路径能够获得的最大黄金

        for (int k = 0; k < 4; k++)                       // 枚举四个移动方向
        {
            int x = i + dx[k];                            // 计算下一位置的行坐标
            int y = j + dy[k];                            // 计算下一位置的列坐标

            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0 && !check[x][y]) // 判断下一位置是否可以访问
            {
                check[x][y] = true;                       // 标记下一位置已经访问
                dfs(grid, x, y, path + grid[x][y]);        // 递归搜索下一位置并累计黄金数量
                check[x][y] = false;                      // 回溯撤销当前位置访问状态
            }
        }
    }
};