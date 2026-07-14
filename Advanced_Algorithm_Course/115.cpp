// https://leetcode.cn/problems/distinct-subsequences/


class Solution
{
public:
    // 计算字符串 s 中有多少个不同子序列可以变成字符串 t
    int numDistinct(string s, string t)
    {
        // m 表示目标字符串 t 的长度
        int m = t.size();
        // n 表示原字符串 s 的长度
        int n = s.size();
        // dp[i][j] 表示用 s[0...j-1] 组成 t[0...i-1] 的方案数
        vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1));
        // 空字符串 t 可以由任意 s 的前缀删除所有字符得到，所以方案数为 1
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        // 枚举目标字符串 t 的前 i 个字符
        for (int i = 1; i <= m; i++)
        {
            // 枚举原字符串 s 的前 j 个字符
            for (int j = 1; j <= n; j++)
            {
                // 不使用 s[j-1] 这个字符，方案数继承 dp[i][j-1]
                dp[i][j] += dp[i][j - 1];
                // 如果 s[j-1] 和 t[i-1] 相等，可以使用 s[j-1] 去匹配 t[i-1]
                if (s[j - 1] == t[i - 1])
                    // 使用 s[j-1] 时，方案数加上前面部分的匹配方案
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        // 返回用整个 s 组成整个 t 的方案数
        return dp[m][n];
    }
};