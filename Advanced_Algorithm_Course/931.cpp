// https://leetcode.cn/problems/minimum-falling-path-sum/


//dp[i][j] = min(左上方, 正上方, 右上方) + 当前格子的值
//因为下降路径每次只能从上一行的这三个位置走下来：
//dp[i - 1][j - 1]  // 左上
//dp[i - 1][j]      // 正上
//dp[i - 1][j + 1]  // 右上
//最后答案就是最后一行 dp[m][1] 到 dp[m][n] 中的最小值。
class Solution
{
public:

    // 计算矩阵中的最小下降路径和
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        // m 表示矩阵的行数
        int m = matrix.size();
        // n 表示矩阵的列数
        int n = matrix[0].size();

        // dp[i][j] 表示走到第 i 行第 j 列时的最小路径和，两边多开一列防止越界
        vector<vector<int>> dp(m + 1, vector<int>(n + 2, INT_MAX));
        // 初始化第 0 行为 0，方便从第 1 行开始递推
        dp[0] = vector<int>(n + 2, 0);
        // ret 用来记录最后一行中的最小路径和
        int ret = INT_MAX;

        // 从第 1 行开始遍历到第 m 行
        for (int i = 1; i <= m; i++)
        {
            // 从第 1 列开始遍历到第 n 列
            for (int j = 1; j <= n; j++)
            {
                // 当前最小路径和 = 上一行左上、正上、右上三者最小值 + 当前格子的值
                dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1] }) + matrix[i - 1][j - 1];
                // 如果已经到最后一行，就更新答案
                if (i == m)
                    // 取最后一行所有位置中的最小值
                    ret = min(ret, dp[i][j]);
            }
        }
        // 返回最小下降路径和
        return ret;
    }
};