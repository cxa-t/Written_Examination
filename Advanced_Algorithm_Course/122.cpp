// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

class Solution
{
public:
    int maxProfit(vector<int>& prices) // 返回可以进行多次股票买卖时能够获得的最大利润
    {
        int n = prices.size(); // 获取价格数组的长度
        int ret = 0; // 记录最终能够获得的总利润
        for (int i = 0; i < n; i++) // 从前往后遍历每一天的股票价格，i 表示当前一段上涨区间的起点
        {
            int j = i; // j 从当前起点 i 开始，向后寻找这一段连续上涨区间的终点
            while (j + 1 < n && prices[j + 1] > prices[j]) j++; // 只要后一天价格比当天高，就继续向后移动，找到这一段连续上涨行情的最高点
            ret += prices[j] - prices[i]; // 在上涨区间的最低点 i 买入，在最高点 j 卖出，将这一段能够获得的利润加入总利润
            i = j; // 将 i 移动到当前上涨区间的终点，下一次循环会从 j 的后一个位置继续寻找新的上涨区间
        }
        return ret; // 返回所有上涨区间利润之和，即可以获得的最大总利润
    }
};