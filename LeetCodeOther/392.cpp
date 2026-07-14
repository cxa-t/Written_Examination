// https://leetcode.cn/problems/is-subsequence/


class Solution
{
public:
    // 判断字符串 s 是否是字符串 t 的子序列
    bool isSubsequence(string s, string t)
    {
        // m 表示字符串 s 的长度
        int m = s.size();
        // n 表示字符串 t 的长度
        int n = t.size();
        // dp[i][j] 表示 s 的前 i 个字符是否是 t 的前 j 个字符的子序列
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        // 空字符串一定是任意字符串的子序列
        for (int j = 0; j <= n; j++) dp[0][j] = true;
        // 枚举 s 的前 i 个字符
        for (int i = 1; i <= m; i++)
        {
            // 枚举 t 的前 j 个字符
            for (int j = 1; j <= n; j++)
            {
                // 如果当前字符相等，可以选择用 t[j-1] 匹配 s[i-1]，也可以跳过 t[j-1]
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1];
                // 如果当前字符不相等，只能跳过 t[j-1]
                else dp[i][j] = dp[i][j - 1];
            }
        }
        // 返回整个 s 是否是整个 t 的子序列
        return dp[m][n];
    }
};