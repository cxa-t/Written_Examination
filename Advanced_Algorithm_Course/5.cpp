// https://leetcode.cn/problems/longest-palindromic-substring/

class Solution
{
public:
    // 求字符串 s 中最长的回文子串
    string longestPalindrome(string s)
    {
        // begin 记录最长回文子串的起始位置
        int begin = 0;
        // len 记录最长回文子串的长度
        int len = 0;
        // n 表示字符串长度
        int n = s.size();
        // 如果字符串长度小于等于 1，它本身就是最长回文子串
        if (n <= 1) return s;
        // dp[i][j] 表示 s[i...j] 是否是回文子串
        vector<vector<bool>> dp(n, vector<bool>(n));
        // 从后往前枚举左端点 i，保证 dp[i + 1][j - 1] 已经被计算过
        for (int i = n - 1; i >= 0; i--)
        {
            // 从 i 开始向右枚举右端点 j
            for (int j = i; j < n; j++)
            {
                // 如果左右两端字符相等，才有可能是回文
                if (s[i] == s[j])
                    // 长度小于等于 2 时直接是回文，否则看中间部分是否是回文
                    dp[i][j] = i + 1 >= j ? true : dp[i + 1][j - 1];
                // 如果 s[i...j] 是回文，并且长度比当前记录的最长长度更大
                if (dp[i][j] && len < j - i + 1)
                {
                    // 更新最长回文子串的起始位置
                    begin = i;
                    // 更新最长回文子串的长度
                    len = j - i + 1;
                }
            }
        }
        // 截取并返回最长回文子串
        return s.substr(begin, len);
    }
};