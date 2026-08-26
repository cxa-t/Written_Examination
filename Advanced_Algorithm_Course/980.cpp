// https://leetcode.cn/problems/unique-paths-iii/


class Solution
{
public:
    vector<vector<bool>> check;                         // 标记每个位置是否已经访问
    int m = 0;                                           // 保存网格行数
    int n = 0;                                           // 保存网格列数
    int num_step = 0;                                    // 记录需要经过的有效格子数量
    int dx[4] = { -1, 1, 0, 0 };                           // 定义上下左右四个方向的行变化
    int dy[4] = { 0, 0, -1, 1 };                           // 定义上下左右四个方向的列变化
    int ret = 0;                                         // 保存满足条件的路径数量

    int uniquePathsIII(vector<vector<int>>& grid)        // 计算经过所有非障碍格子的路径数量
    {
        m = grid.size();                                 // 获取网格行数
        n = grid[0].size();                              // 获取网格列数

        check.resize(m, vector<bool>(n));                // 初始化访问标记数组

        int starti = 0;                                  // 保存起点行坐标
        int startj = 0;                                  // 保存起点列坐标

        for (int i = 0; i < m; i++)                       // 遍历网格所有行
        {
            for (int j = 0; j < n; j++)                   // 遍历网格所有列
            {
                if (grid[i][j] != -1)                     // 统计所有可通行的位置数量
                {
                    num_step++;                          // 有效路径格子数量加一
                    if (grid[i][j] == 1)                  // 找到起点位置
                    {
                        starti = i;                      // 保存起点行
                        startj = j;                      // 保存起点列
                    }
                }
            }
        }

        check[starti][startj] = true;                    // 标记起点已经访问
        dfs(grid, starti, startj, 1);                    // 从起点开始搜索路径
        return ret;                                      // 返回所有满足条件的路径数量
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int count) // 从当前位置继续搜索可行路径
    {
        if (grid[i][j] == 2 && count == num_step)         // 到达终点且经过所有有效格子
        {
            ret++;                                       // 找到一条合法路径
            return;                                      // 当前搜索结束
        }

        for (int k = 0; k < 4; k++)                       // 枚举上下左右四个方向
        {
            int x = dx[k] + i;                           // 计算下一位置行坐标
            int y = dy[k] + j;                           // 计算下一位置列坐标

            if (x >= 0 && x < m && y >= 0 && y < n && !check[x][y] && grid[x][y] != -1) // 判断下一位置是否可以访问
            {
                check[x][y] = true;                      // 标记下一位置已经访问
                dfs(grid, x, y, count + 1);              // 递归搜索下一步并增加经过格子数量
                check[x][y] = false;                     // 回溯恢复下一位置未访问状态
            }
        }
    }
};