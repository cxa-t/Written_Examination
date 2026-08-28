// https://leetcode.cn/problems/max-area-of-island/


class Solution
{
public:
    int m = 0;                                      // 保存网格的行数
    int n = 0;                                      // 保存网格的列数
    vector<vector<bool>> vis;                       // 标记每个位置是否已经访问
    int dx[4] = { 0, 0, -1, 1 };                      // 定义左右上下四个方向的行偏移
    int dy[4] = { -1, 1, 0, 0 };                      // 定义左右上下四个方向的列偏移
    void dfs(vector<vector<int>>& grid, int i, int j, int& path) // 统计当前位置所在岛屿的面积
    {
        vis[i][j] = true;                           // 标记当前陆地已经访问
        path++;                                     // 当前岛屿面积加一

        for (int k = 0; k < 4; k++)                  // 枚举四个相邻方向
        {
            int x = i + dx[k];                      // 计算相邻位置的行坐标
            int y = j + dy[k];                      // 计算相邻位置的列坐标

            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y]) // 判断相邻位置是否为未访问陆地
            {
                dfs(grid, x, y, path);              // 继续递归统计相连陆地面积
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)  // 返回网格中最大岛屿面积
    {
        int ret = 0;                                // 保存当前找到的最大岛屿面积
        m = grid.size();                            // 获取网格的行数
        n = grid[0].size();                         // 获取网格的列数
        vis.resize(m, vector<bool>(n, false));      // 初始化所有位置为未访问状态

        for (int i = 0; i < m; i++)                  // 遍历网格的每一行
        {
            for (int j = 0; j < n; j++)              // 遍历当前行的每一列
            {
                if (grid[i][j] == 1 && vis[i][j] == false) // 找到一个还未访问的陆地起点
                {
                    int path = 0;                    // 初始化当前岛屿面积为0
                    dfs(grid, i, j, path);           // 统计当前整座岛屿的面积
                    ret = max(path, ret);            // 更新最大岛屿面积
                }
            }
        }
        return ret;                                  // 返回最大岛屿面积
    }
};