// https://leetcode.cn/problems/edit-distance/?envType=study-plan-v2&envId=top-100-liked


class Solution
{
public:
    // 计算将字符串 s1 转换成字符串 s2 所需的最少操作次数
    int minDistance(string s1, string s2)
    {
        // m 表示字符串 s1 的长度
        int m = s1.size();
        // n 表示字符串 s2 的长度
        int n = s2.size();
        // dp[i][j] 表示将 s1 前 i 个字符转换成 s2 前 j 个字符的最少操作次数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 当 s1 为空时，只能通过插入 j 个字符变成 s2 的前 j 个字符
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        // 当 s2 为空时，只能通过删除 i 个字符把 s1 的前 i 个字符变成空串
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        // 枚举 s1 的前 i 个字符
        for (int i = 1; i <= m; i++)
        {
            // 枚举 s2 的前 j 个字符
            for (int j = 1; j <= n; j++)
            {
                // 如果当前两个字符相等，不需要操作，直接继承左上角状态
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                // 如果当前两个字符不相等，就从插入、替换、删除三种操作中取最小值
                else dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
            }
        }
        // 返回将整个 s1 转换成整个 s2 的最少操作次数
        return dp[m][n];
    }
};