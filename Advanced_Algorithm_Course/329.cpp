// https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/


class Solution
{
public:
    int dx[4] = { -1, 1, 0, 0 };                         // 定义上下左右四个方向的行偏移
    int dy[4] = { 0, 0, -1, 1 };                         // 定义上下左右四个方向的列偏移
    int m = 0;                                         // 保存矩阵的行数
    int n = 0;                                         // 保存矩阵的列数
    vector<vector<int>> memo;                          // 记录每个位置出发的最长递增路径长度
    int longestIncreasingPath(vector<vector<int>>& matrix) // 返回矩阵中的最长递增路径长度
    {
        int ret = 0;                                   // 保存全局最长递增路径长度
        m = matrix.size();                             // 获取矩阵的行数
        n = matrix[0].size();                          // 获取矩阵的列数
        memo.resize(m, vector<int>(n));                // 初始化记忆数组
        for (int i = 0; i < m; i++)                     // 遍历矩阵中的每一行
        {
            for (int j = 0; j < n; j++)                 // 遍历当前行中的每一列
            {
                ret = max(ret, dfs(matrix, i, j));     // 更新所有起点中的最长递增路径
            }
        }
        return ret;                                    // 返回全局最长递增路径长度
    }
    int dfs(vector<vector<int>>& matrix, int i, int j) // 计算从当前位置出发的最长递增路径长度
    {
        if (memo[i][j]) return memo[i][j];             // 当前状态已计算则直接返回缓存结果
        int ret = 1;                                   // 至少包含当前节点自身所以初始长度为1
        for (int k = 0; k < 4; k++)                     // 枚举上下左右四个方向
        {
            int x = dx[k] + i;                         // 计算相邻位置的行坐标
            int y = dy[k] + j;                         // 计算相邻位置的列坐标
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) // 判断相邻位置是否更大且在边界内
            {
                ret = max(ret, dfs(matrix, x, y) + 1); // 递归计算下一位置并更新最长递增路径
            }
        }
        memo[i][j] = ret;                              // 缓存当前位置对应的最长递增路径长度
        return memo[i][j];                             // 返回当前位置的最长递增路径长度
    }
};