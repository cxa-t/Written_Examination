// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/


class Solution
{
public:
    // 计算带手续费的股票买卖最大利润
    int maxProfit(vector<int>& prices, int fee)
    {
        // n 表示股票价格数组的长度
        int n = prices.size();
        // f[i] 表示第 i 天结束后，手里持有股票时的最大利润
        vector<int> f(n);
        // g[i] 表示第 i 天结束后，手里没有股票时的最大利润
        vector<int> g(n);
        // 第 0 天如果持有股票，只能是当天买入，所以利润是 -prices[0]
        f[0] = -prices[0];
        // 从第 1 天开始进行状态转移
        for (int i = 1; i < n; i++)
        {
            // 今天持有股票：要么昨天就持有，要么昨天没股票今天买入
            f[i] = max(f[i - 1], g[i - 1] - prices[i]);
            // 今天没有股票：要么昨天就没有股票，要么昨天持有股票今天卖出并支付手续费
            g[i] = max(g[i - 1], f[i - 1] - fee + prices[i]);
        }
        // 返回最后一天持有或不持有股票两种状态中的最大利润
        return max(f[n - 1], g[n - 1]);
    }
};