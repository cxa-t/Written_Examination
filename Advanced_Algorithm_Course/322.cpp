// https://leetcode.cn/problems/coin-change/

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)                    // 计算凑出目标金额所需的最少硬币数量
    {
        int INF = 0x3f3f3f3f;                                        // 定义一个足够大的值表示当前金额无法凑出
        int n = coins.size();                                         // 获取硬币种类数量
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));      // dp[i][j]表示前i种硬币凑出金额j的最少硬币数
        for (int j = 1; j <= amount; j++) dp[0][j] = INF;             // 没有硬币时无法凑出任何正金额
        for (int i = 1; i <= n; i++)                                  // 依次考虑每一种硬币
        {
            for (int j = 0; j <= amount; j++)                         // 枚举当前需要凑出的金额
            {
                dp[i][j] = dp[i - 1][j];                               // 不选择当前硬币时继承上一层结果
                if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INF) // 剩余金额可达时才能继续使用当前硬币
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1); // 比较使用和不使用当前硬币的最少数量
            }
        }
        return dp[n][amount] == INF ? -1 : dp[n][amount];             // 无法凑出目标金额返回-1否则返回最少硬币数
    }
};