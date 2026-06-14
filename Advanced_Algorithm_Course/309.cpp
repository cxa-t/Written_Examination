// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/


class Solution
{
public:
    // 计算含冷冻期的股票买卖最大利润
    int maxProfit(vector<int>& prices)
    {
        // n 表示股票价格数组的长度
        int n = prices.size();
        // dp[i][0] 表示第 i 天结束后，手里持有股票时的最大利润
        // dp[i][1] 表示第 i 天结束后，手里没有股票，并且不是今天卖出的最大利润
        // dp[i][2] 表示第 i 天结束后，今天刚卖出股票的最大利润
        vector<vector<int>> dp(n, vector<int>(3));
        // 第 0 天如果持有股票，只能是当天买入，所以利润是 -prices[0]
        dp[0][0] = -prices[0];
        // 第 0 天不持有股票，利润为 0
        dp[0][1] = 0;
        // 第 0 天不可能卖出股票，这里初始化为 0
        dp[0][2] = 0;
        // 从第 1 天开始进行状态转移
        for (int i = 1; i < n; i++)
        {
            // 今天持有股票：要么昨天就持有，要么昨天不是刚卖出、今天买入
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 今天不持有且不是今天卖出：要么昨天也不持有，要么昨天刚卖出今天冷冻
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            // 今天刚卖出股票：只能是昨天持有股票，今天卖出
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        // 最后一天不能还持有股票，答案是不持有股票的两种状态最大值
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};