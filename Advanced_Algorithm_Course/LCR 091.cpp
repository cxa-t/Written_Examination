// https://leetcode.cn/problems/JEj789/

class Solution
{
public:
    // 计算粉刷所有房子的最小总花费
    int minCost(vector<vector<int>>& costs)
    {
        // m 表示房子的数量
        int m = costs.size();
        // dp[i][j] 表示刷完前 i 个房子，并且第 i 个房子刷成颜色 j 的最小花费
        vector<vector<int>> dp(m + 1, vector<int>(3));
        // 从第 1 个房子开始遍历到第 m 个房子
        for (int i = 1; i <= m; i++)
        {
            // 当前房子刷成颜色 0，上一个房子只能刷成颜色 1 或 2
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            // 当前房子刷成颜色 1，上一个房子只能刷成颜色 0 或 2
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            // 当前房子刷成颜色 2，上一个房子只能刷成颜色 0 或 1
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i - 1][2];
        }
        // 返回最后一个房子刷成三种颜色时的最小值
        return min(dp[m][0], min(dp[m][1], dp[m][2]));
    }
};