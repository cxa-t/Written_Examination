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

//贪心
class Solution
{
public:
    int maxProfit(vector<int>& prices) // 返回只进行一次股票买卖能够获得的最大利润
    {
        int ret = 0; // 记录当前能够获得的最大利润，初始为0，表示最差情况是不进行交易
        int prevMin = INT_MAX; // 记录当前位置之前出现过的最低股票价格，初始设为最大整数
        for (int i = 0; i < prices.size(); i++) // 从前往后遍历每天的股票价格
        {
            ret = max(ret, prices[i] - prevMin); // 假设在之前最低价格 prevMin 时买入、今天 prices[i] 卖出，计算利润并更新最大利润
            prevMin = min(prevMin, prices[i]); // 更新到目前为止出现过的最低股票价格，为后面的卖出提供更低的买入价格
        }
        return ret; // 返回一次买入和一次卖出能够获得的最大利润
    }
};
