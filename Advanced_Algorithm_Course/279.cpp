// https://leetcode.cn/problems/perfect-squares/


class Solution
{
public:
    int numSquares(int n)                                             // 计算和为n的完全平方数的最少数量
    {
        int row = static_cast<int>(sqrt(n) + 1);                      // 计算需要考虑的平方数种类数量
        vector<vector<int>> dp(row + 1, vector<int>(n + 1));          // dp[i][j]表示前i个平方数凑出j的最少数量
        for (int j = 1; j <= n; j++) dp[0][j] = 0x3f3f3f3f;           // 没有平方数时无法凑出任何正数
        for (int i = 1; i <= row; i++)                                 // 依次考虑每一个完全平方数
        {
            for (int j = 0; j <= n; j++)                               // 枚举当前需要凑出的目标和
            {
                dp[i][j] = dp[i - 1][j];                                // 不使用当前平方数时继承上一层结果
                if (j >= i * i)                                        // 当前目标值能够使用平方数i*i
                    dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);         // 比较使用和不使用当前平方数的最少数量
            }
        }
        return dp[row][n];                                            // 返回凑出n所需的最少完全平方数数量
    }
};