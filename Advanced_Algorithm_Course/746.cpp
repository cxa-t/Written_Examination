// https://leetcode.cn/problems/min-cost-climbing-stairs/

#include<iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 计算爬到楼顶所需的最小花费
    int minCostClimbingStairs(vector<int>& cost)
    {
        // n 表示楼梯台阶数量
        int n = cost.size();
        // dp[i] 表示到达第 i 阶所需要的最小花费
        vector<int> dp(n + 1);
        // 从第 2 阶开始递推，因为可以从第 0 阶或第 1 阶起步
        for (int i = 2; i <= n; i++)
            // 到达第 i 阶，可以从 i-1 或 i-2 阶跳上来，取较小花费
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        // dp[n] 表示到达楼顶的最小花费
        return dp[n];
    }
};

int main()
{
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
    Solution().minCostClimbingStairs(cost);
    return 0;
}