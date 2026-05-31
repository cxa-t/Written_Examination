// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/

// 每个格子只能从上方或左方走过来，所以选择价值更大的那条路径，再加上当前格子的珠宝价值。
class Solution
{
public:
    // 计算从左上角到右下角能拿到的最大珠宝价值
    int jewelleryValue(vector<vector<int>>& frame)
    {
        // m 表示网格的行数
        int m = frame.size();
        // n 表示网格的列数
        int n = frame[0].size();
        // dp[i][j] 表示走到第 i 行第 j 列时能获得的最大价值
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // 从第 1 行遍历到第 m 行
        for (int i = 1; i <= m; i++)
        {
            // 从第 1 列遍历到第 n 列
            for (int j = 1; j <= n; j++)
            {
                // 当前最大价值 = 上方或左方的较大价值 + 当前格子的价值
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
            }
        }
        // 返回走到右下角时能获得的最大价值
        return dp[m][n];
    }
};