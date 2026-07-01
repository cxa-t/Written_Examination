// https://leetcode.cn/problems/palindromic-substrings/


class Solution
{
public:
    // 统计字符串 s 中回文子串的数量
    int countSubstrings(string s)
    {
        // n 表示字符串长度
        int n = s.size();
        // dp[i][j] 表示 s[i...j] 是否是回文子串
        vector<vector<bool>> dp(n, vector<bool>(n));
        // ret 用来记录回文子串的总数量
        int ret = 0;
        // 从后往前枚举左端点 i，保证 dp[i + 1][j - 1] 已经被计算过
        for (int i = n - 1; i >= 0; i--)
        {
            // 从 i 开始往后枚举右端点 j
            for (int j = i; j < n; j++)
            {
                // 如果左右两端字符相等，才有可能构成回文
                if (s[i] == s[j])
                {
                    // 如果长度小于等于 2，直接是回文；否则看中间部分是否是回文
                    dp[i][j] = i + 1 >= j ? true : dp[i + 1][j - 1];
                }
                // 如果 s[i...j] 是回文子串
                if (dp[i][j])
                {
                    // 回文子串数量加 1
                    ret += 1;
                }
            }
        }
        // 返回回文子串总数量
        return ret;
    }
};