// https://leetcode.cn/problems/unique-paths-ii/


// 如果当前格子不是障碍物，路径数就等于左边路径数 + 上边路径数；
// 如果当前格子是障碍物，那就不能走，dp[i][j] 保持为 0。
class Solution 
{
public:
    // 计算带障碍物的网格中，从左上角到右下角的不同路径数量
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        // m 表示网格的行数
        int m = obstacleGrid.size();
        // n 表示网格的列数
        int n = obstacleGrid[0].size();
        // dp[i][j] 表示走到第 i 行第 j 列的路径数量
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 初始化入口的前一个位置，方便统一递推
        dp[0][1] = 1;

        // 从第 1 行遍历到第 m 行
        for (int i = 1; i <= m; i++)
        {
            // 从第 1 列遍历到第 n 列
            for (int j = 1; j <= n; j++)
            {
                // 如果当前位置不是障碍物，才可以计算路径数
                if (obstacleGrid[i - 1][j - 1] == 0)
                {
                    // 当前路径数 = 左边路径数 + 上边路径数
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        // 返回走到右下角的路径数量
        return dp[m][n];
    }
};