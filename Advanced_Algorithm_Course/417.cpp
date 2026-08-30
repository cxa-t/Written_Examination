// https://leetcode.cn/problems/pacific-atlantic-water-flow/

class Solution
{
public:
    int m = 0;                                      // 保存矩阵的行数
    int n = 0;                                      // 保存矩阵的列数
    int dx[4] = { 0, 0, -1, 1 };                      // 定义左右上下四个方向的行偏移
    int dy[4] = { -1, 1, 0, 0 };                      // 定义左右上下四个方向的列偏移
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& vis) // 从海洋边界反向搜索可到达的位置
    {
        vis[i][j] = true;                           // 标记当前位置可以流向当前海洋
        for (int k = 0; k < 4; k++)                  // 枚举上下左右四个方向
        {
            int x = i + dx[k];                      // 计算相邻位置的行坐标
            int y = j + dy[k];                      // 计算相邻位置的列坐标
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && heights[x][y] >= heights[i][j]) // 判断相邻位置是否能反向流到当前位置
                dfs(heights, x, y, vis);            // 继续反向搜索更高或等高的位置
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) // 找出同时能流向太平洋和大西洋的位置
    {
        m = heights.size();                         // 获取矩阵的行数
        n = heights[0].size();                      // 获取矩阵的列数
        vector<vector<int>> ret;                    // 保存最终满足条件的位置
        vector<vector<bool>> visao(m, vector<bool>(n)); // 标记可以流向大西洋的位置
        vector<vector<bool>> vispo(m, vector<bool>(n)); // 标记可以流向太平洋的位置
        for (int j = 0; j < n; j++)                  // 遍历矩阵的上下边界
        {
            if (!vispo[0][j]) dfs(heights, 0, j, vispo); // 从上边界反向搜索太平洋可达区域
            if (!visao[m - 1][j]) dfs(heights, m - 1, j, visao); // 从下边界反向搜索大西洋可达区域
        }
        for (int i = 0; i < m; i++)                  // 遍历矩阵的左右边界
        {
            if (!vispo[i][0]) dfs(heights, i, 0, vispo); // 从左边界反向搜索太平洋可达区域
            if (!visao[i][n - 1]) dfs(heights, i, n - 1, visao); // 从右边界反向搜索大西洋可达区域
        }
        for (int i = 0; i < m; i++)                  // 遍历矩阵中的每一行
        {
            for (int j = 0; j < n; j++)              // 遍历当前行中的每一列
            {
                if (visao[i][j] && vispo[i][j])      // 判断当前位置是否同时能到达两个海洋
                {
                    ret.push_back({ i, j });           // 将满足条件的位置加入结果集
                }
            }
        }
        return ret;                                 // 返回所有同时可达两个海洋的位置
    }
};