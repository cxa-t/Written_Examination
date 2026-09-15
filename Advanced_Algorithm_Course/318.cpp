// https://leetcode.cn/problems/coin-change-ii/


class Solution
{
public:
    int change(int amount, vector<int>& coins)                         // 计算凑出目标金额的组合方案数量
    {
        int n = coins.size();                                          // 获取硬币种类数量
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(amount + 1)); // dp[i][j]表示前i种硬币凑出金额j的方案数
        dp[0][0] = 1;                                                  // 不使用任何硬币凑出金额0有一种方案
        for (int i = 1; i <= n; i++)                                   // 依次考虑每一种硬币
        {
            for (int j = 0; j <= amount; j++)                          // 枚举当前需要凑出的金额
            {
                dp[i][j] += dp[i - 1][j];                               // 加上不使用当前硬币时的方案数量
                if (j >= coins[i - 1])                                   // 当前金额能够使用第i种硬币
                    dp[i][j] += dp[i][j - coins[i - 1]];                  // 加上至少使用一枚当前硬币后的方案数量
            }
        }
        return static_cast<int>(dp[n][amount]);                       // 返回凑出目标金额的所有组合方案数
    }
};