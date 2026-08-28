// https://leetcode.cn/problems/number-of-islands/


class Solution
{
public:
    int m = 0;                                      // 保存网格的行数
    int n = 0;                                      // 保存网格的列数
    int ret = 0;                                    // 记录岛屿的数量
    int dx[4] = { -1, 1, 0, 0 };                      // 定义上下左右四个方向的行偏移
    int dy[4] = { 0, 0, -1, 1 };                      // 定义上下左右四个方向的列偏移
    void dfs(vector<vector<char>>& grid, int i, int j) // 将与当前位置相连的整座岛屿全部淹没
    {
        grid[i][j] = '0';                           // 将当前陆地标记为已经访问
        for (int k = 0; k < 4; k++)                  // 枚举上下左右四个方向
        {
            int x = dx[k] + i;                      // 计算相邻位置的行坐标
            int y = dy[k] + j;                      // 计算相邻位置的列坐标
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '0') // 判断相邻位置是否为未访问的陆地
            {
                dfs(grid, x, y);                    // 继续递归淹没相连的陆地
            }
        }
    }
    int numIslands(vector<vector<char>>& grid)      // 统计网格中的岛屿数量
    {
        m = grid.size();                            // 获取网格的行数
        n = grid[0].size();                         // 获取网格的列数
        for (int i = 0; i < m; i++)                  // 遍历网格中的每一行
        {
            for (int j = 0; j < n; j++)              // 遍历当前行中的每一列
            {
                if (grid[i][j] != '0')               // 找到一个还没有访问过的陆地
                {
                    dfs(grid, i, j);                 // 将当前陆地所在的整座岛屿全部标记
                    ret++;                           // 完整找到一座岛屿后数量加一
                }
            }
        }
        return ret;                                 // 返回岛屿总数量
    }
};