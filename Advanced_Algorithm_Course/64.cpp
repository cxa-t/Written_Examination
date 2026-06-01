// https://leetcode.cn/problems/minimum-path-sum/


// dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1]
// 因为每次只能向右或向下走，所以到达当前位置只能从上方或左方过来，选择路径和更小的那一条。
class Solution
{
public:
    // 计算从左上角到右下角的最小路径和
    int minPathSum(vector<vector<int>>& grid)
    {
        // m 表示网格的行数
        int m = grid.size();
        // n 表示网格的列数
        int n = grid[0].size();
        // dp[i][j] 表示走到第 i 行第 j 列的最小路径和
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        // 初始化入口前一个位置为 0，方便统一递推
        dp[0][1] = 0;

        // 从第 1 行开始遍历到第 m 行
        for (int i = 1; i <= m; i++)
        {
            // 从第 1 列开始遍历到第 n 列
            for (int j = 1; j <= n; j++)
            {
                // 当前最小路径和 = 上方或左方较小路径和 + 当前格子的值
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        // 返回走到右下角的最小路径和
        return dp[m][n];
    }
};