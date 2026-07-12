// https://leetcode.cn/problems/longest-common-subsequence/


class Solution
{
public:
    // 计算两个字符串的最长公共子序列长度
    int longestCommonSubsequence(string s1, string s2)
    {
        // m 表示字符串 s1 的长度
        int m = s1.size();
        // n 表示字符串 s2 的长度
        int n = s2.size();
        // 在 s1 前面加一个空格，使字符串下标从 1 开始，方便 dp 对应
        s1 = " " + s1;
        // 在 s2 前面加一个空格，使字符串下标从 1 开始，方便 dp 对应
        s2 = " " + s2;
        // dp[i][j] 表示 s1[1...i] 和 s2[1...j] 的最长公共子序列长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 枚举 s1 的前 i 个字符
        for (int i = 1; i <= m; i++)
        {
            // 枚举 s2 的前 j 个字符
            for (int j = 1; j <= n; j++)
            {
                // 如果当前两个字符相等，就可以接在前面的公共子序列后面
                if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                // 如果当前两个字符不相等，就分别去掉一个字符，取较大值
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        // 返回两个完整字符串的最长公共子序列长度
        return dp[m][n];
    }
};