// https://leetcode.cn/problems/profitable-schemes/


class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) // 计算人数不超过n且利润至少为minProfit的方案数量
    {
        const int MOD = 1e9 + 7; // 定义取模常数防止结果溢出
        int count = group.size(); // 获取项目总数量
        vector<vector<vector<int>>> dp(count + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1))); // dp[i][j][k]表示前i个项目使用不超过j个人且利润至少为k的方案数
        for (int j = 0; j <= n; j++) dp[0][j][0] = 1; // 不选择任何项目时利润至少为0有一种方案
        for (int i = 1; i <= count; i++) // 依次考虑每一个项目
        {
            for (int j = 0; j <= n; j++) // 枚举当前最多可以使用的人数
            {
                for (int k = 0; k <= minProfit; k++) // 枚举当前要求达到的最低利润
                {
                    dp[i][j][k] += dp[i - 1][j][k]; // 不选择当前项目时继承上一层方案数
                    if (j >= group[i - 1]) // 当前人数限制能够容纳当前项目
                        dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])]; // 加上选择当前项目后剩余利润需求对应的方案数
                    dp[i][j][k] %= MOD; // 对当前方案数量取模
                }
            }
        }
        return dp[count][n][minProfit]; // 返回所有项目中满足人数和最低利润要求的方案数
    }
};