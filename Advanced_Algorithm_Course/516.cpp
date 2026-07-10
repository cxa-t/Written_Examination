// https://leetcode.cn/problems/longest-palindromic-subsequence/

class Solution
{
public:
    // 计算字符串 s 的最长回文子序列长度
    int longestPalindromeSubseq(string s)
    {
        // n 表示字符串长度
        int n = s.size();
        // dp[i][j] 表示 s[i...j] 范围内的最长回文子序列长度
        vector<vector<int>> dp(n, vector<int>(n));
        // 从后往前枚举左端点 i，保证 dp[i + 1][j - 1] 已经计算过
        for (int i = n - 1; i >= 0; i--)
        {
            // 单个字符本身就是回文子序列，长度为 1
            dp[i][i] = 1;
            // 枚举右端点 j，范围是 i + 1 到 n - 1
            for (int j = i + 1; j < n; j++)
            {
                // 如果两端字符相等，可以把这两个字符加入中间回文子序列
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                // 如果两端字符不相等，只能分别去掉左端或右端，取较大值
                else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        // 返回整个字符串范围内的最长回文子序列长度
        return dp[0][n - 1];
    }
};