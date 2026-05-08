// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        //思路：
        //将暴力的代码写纸上模拟，思考到最佳时机就是低价买入，高价卖出
        //注意：这里不是全局低价，而是当前价值前的最低价
        //所以只需要维护这两个变量就好了
        int ret = 0;
        int n = prices.size();
        if (n <= 1) return ret;
        int minl = prices[0];
        for (int i = 1; i < n; i++)
        {
            ret = max(ret, prices[i] - minl);
            minl = min(minl, prices[i]);
        }
        return ret;
    }
};