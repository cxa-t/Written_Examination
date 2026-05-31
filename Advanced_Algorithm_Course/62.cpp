// https://leetcode.cn/problems/unique-paths/


// dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
// 因为机器人每次只能向下或向右走，所以到达当前位置只能从它的上面或左边走过来。
class Solution
{
public:
    // 计算从左上角走到右下角的不同路径数量
    int uniquePaths(int m, int n)
    {
        // dp[i][j] 表示走到第 i 行第 j 列的路径数量
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 初始化入口的前一个位置，方便统一递推
        dp[0][1] = 1;
        // 从第 1 行开始遍历到第 m 行
        for (int i = 1; i <= m; i++)
        {
            // 从第 1 列开始遍历到第 n 列
            for (int j = 1; j <= n; j++)
            {
                // 当前格子的路径数 = 上方格子的路径数 + 左方格子的路径数
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // 返回走到右下角的路径数量
        return dp[m][n];
    }
};