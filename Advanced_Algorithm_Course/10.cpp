// https://leetcode.cn/problems/regular-expression-matching/


class Solution {
public:
    // 判断字符串 s 是否能被正则表达式 p 完全匹配
    bool isMatch(string s, string p)
    {
        // m 表示字符串 s 的长度，n 表示模式串 p 的长度
        int m = s.size(), n = p.size();
        // 在 s 和 p 前面加空格，使下标从 1 开始，方便 dp 对应
        s = " " + s, p = " " + p;
        // dp[i][j] 表示 s[1...i] 是否能被 p[1...j] 完全匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        // 空字符串和空模式串可以匹配
        dp[0][0] = true;
        // 初始化 s 为空时，p 是否可以匹配空字符串
        for (int j = 2; j <= n; j += 2)
        {
            // 如果当前字符是 '*'，它可以让前一个字符出现 0 次
            if (p[j] == '*')
                // 这里表示 p[1...j] 可以匹配空字符串
                dp[0][j] = true;
            // 一旦遇到不能消除的结构，就无法继续匹配空字符串
            else
                break;
        }
        // 枚举字符串 s 的前 i 个字符
        for (int i = 1; i <= m; i++)
        {
            // 枚举模式串 p 的前 j 个字符
            for (int j = 1; j <= n; j++)
            {
                // 如果当前模式字符是 '*'
                if (p[j] == '*')
                    // '*' 可以让前一个字符出现 0 次，也可以让前一个字符重复匹配当前 s[i]
                    dp[i][j] = dp[i][j - 2] ||
                    (p[j - 1] == '.' || p[j - 1] == s[i]) && dp[i - 1][j];
                // 如果当前模式字符不是 '*'
                else
                    // 当前字符能匹配，并且前面的部分也能匹配，当前状态才为 true
                    dp[i][j] = (p[j] == s[i] || p[j] == '.') && dp[i - 1][j - 1];
            }
        }
        // 返回整个 s 是否能被整个 p 完全匹配
        return dp[m][n];
    }
};