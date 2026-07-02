// https://leetcode.cn/problems/palindrome-partitioning-iv/


class Solution
{
public:
    // 判断字符串 s 是否可以被分成 3 个非空回文子串
    bool checkPartitioning(string s)
    {
        // n 表示字符串长度
        int n = s.size();
        // dp[i][j] 表示 s[i...j] 是否是回文子串
        vector<vector<bool>> dp(n, vector<bool>(n));
        // 从后往前枚举左端点 i，保证 dp[i + 1][j - 1] 已经提前算好
        for (int i = n - 1; i >= 0; i--)
        {
            // 从 i 开始枚举右端点 j
            for (int j = i; j < n; j++)
            {
                // 如果左右两端字符相等，才有可能是回文
                if (s[i] == s[j])
                {
                    // 长度小于等于 2 时直接是回文，否则看中间部分是否是回文
                    dp[i][j] = i + 1 >= j ? true : dp[i + 1][j - 1];
                }
            }
        }
        // 枚举第二段回文子串的起始位置 i
        for (int i = 1; i < n - 1; i++)
        {
            // 枚举第二段回文子串的结束位置 j
            for (int j = i; j < n - 1; j++)
            {
                // 判断三段 s[0...i-1]、s[i...j]、s[j+1...n-1] 是否全是回文
                if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1])
                {
                    // 如果存在一种合法划分，直接返回 true
                    return true;
                }
            }
        }
        // 如果所有划分方式都不满足，返回 false
        return false;
    }
};