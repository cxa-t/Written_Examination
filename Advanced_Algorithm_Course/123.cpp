// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/


//f[i][j] // 第 i 天结束后，手里有股票，已经完成 j 次交易
//g[i][j] // 第 i 天结束后，手里没股票，已经完成 j 次交易
class Solution
{
public:
    // 计算最多完成两次股票交易时的最大利润
    int maxProfit(vector<int>& prices)
    {
        // 用一个很大的数表示负无穷的相反数
        int INTMIN = 0x3f3f3f3f;
        // n 表示股票价格数组的长度
        int n = prices.size();
        // f[i][j] 表示第 i 天结束后，手里有股票，并且已经完成 j 次交易的最大利润
        vector<vector<int>> f(n, vector<int>(3, -INTMIN));
        // g[i][j] 表示第 i 天结束后，手里没有股票，并且已经完成 j 次交易的最大利润
        vector<vector<int>> g(n, vector<int>(3, -INTMIN));
        // 第 0 天买入股票，此时手里有股票，完成交易次数为 0
        f[0][0] = -prices[0];
        // 第 0 天什么都不做，此时手里没有股票，完成交易次数为 0
        g[0][0] = 0;
        // 从第 1 天开始进行状态转移
        for (int i = 1; i < n; i++)
        {
            // 枚举已经完成的交易次数，最多 2 次
            for (int j = 0; j < 3; j++)
            {
                // 今天手里有股票：要么昨天就有股票，要么昨天没股票今天买入
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                // 今天手里没股票：先继承昨天没股票的状态
                g[i][j] = g[i - 1][j];
                // 如果 j 大于 0，说明今天可以通过卖出股票完成第 j 次交易
                if (j - 1 >= 0)
                    // 今天手里没股票：也可能是昨天有股票，今天卖出并完成一次交易
                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
            }
        }
        // 最后一天手里不能有股票，返回完成 0、1、2 次交易中的最大利润
        return max(max(g[n - 1][0], g[n - 1][1]), g[n - 1][2]);
    }
};