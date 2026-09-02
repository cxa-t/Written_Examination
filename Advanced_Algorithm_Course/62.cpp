// https://leetcode.cn/problems/unique-paths/


// dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
// 因为机器人每次只能向下或向右走，所以到达当前位置只能从它的上面或左边走过来。
class Solution
{
public:
    // 计算从左上角走到右下角的不同路径数量
    int uniquePaths(int m, int n)
    {
        // dp[i][j] 表示走到第 i 行第 j 列的路径数量
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 初始化入口的前一个位置，方便统一递推
        dp[0][1] = 1;
        // 从第 1 行开始遍历到第 m 行
        for (int i = 1; i <= m; i++)
        {
            // 从第 1 列开始遍历到第 n 列
            for (int j = 1; j <= n; j++)
            {
                // 当前格子的路径数 = 上方格子的路径数 + 左方格子的路径数
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // 返回走到右下角的路径数量
        return dp[m][n];
    }
};


class Solution
{
public:
    int uniquePaths(int m, int n)                         // 计算从左上角到右下角的不同路径数量
    {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1)); // 初始化记忆数组保存子问题结果
        dfs(memo, m, n);                                  // 从终点开始递归计算路径数量
        return memo[m][n];                                // 返回最终路径数量
    }
    int dfs(vector<vector<int>>& memo, int i, int j)      // 计算到达(i,j)位置的路径数量
    {
        if (i == 0 || j == 0)                              // 判断是否越过网格边界
        {
            memo[i][j] = 0;                               // 边界外位置没有有效路径
            return 0;                                    // 返回无效路径数量
        }
        if (i == 1 && j == 1)                              // 判断是否到达起点位置
        {
            memo[i][j] = 1;                               // 起点到自身只有一种路径
            return 1;                                    // 返回起点路径数量
        }
        if (memo[i][j] != -1)                              // 判断当前子问题是否已经计算
        {
            return memo[i][j];                            // 直接返回缓存结果
        }
        memo[i][j] = dfs(memo, i - 1, j) + dfs(memo, i, j - 1); // 当前路径数等于上方和左方路径数之和
        return memo[i][j];                                // 返回当前位置的路径数量
    }
};