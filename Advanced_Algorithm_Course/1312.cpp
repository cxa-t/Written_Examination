// https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution
{
public:
    // 计算把字符串 s 变成回文串所需要的最少插入次数
    int minInsertions(string s)
    {
        // n 表示字符串长度
        int n = s.size();
        // dp[i][j] 表示把 s[i...j] 变成回文串所需要的最少插入次数
        vector<vector<int>> dp(n, vector<int>(n));
        // 从后往前枚举左端点 i，保证 dp[i+1][j-1]、dp[i+1][j] 已经计算过
        for (int i = n - 1; i >= 0; i--)
        {
            // 枚举右端点 j，j 必须在 i 的右边
            for (int j = i + 1; j < n; j++)
            {
                // 如果左右两端字符相等，不需要额外插入，只看中间部分
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                // 如果左右两端字符不相等，就在左边或右边插入一个字符，取较小值
                else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
        // 返回整个字符串变成回文串所需要的最少插入次数
        return dp[0][n - 1];
    }
};