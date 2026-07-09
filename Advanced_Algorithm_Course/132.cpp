// https://leetcode.cn/problems/palindrome-partitioning-ii/

class Solution
{
public:
    // 计算将字符串切分成若干回文子串所需的最少切割次数
    int minCut(string s)
    {
        // n 表示字符串长度
        int n = s.size();
        // ispal[i][j] 表示 s[i...j] 是否是回文子串
        vector<vector<bool>> ispal(n, vector<bool>(n));
        // 从后往前枚举左端点，保证 ispal[i+1][j-1] 已经被计算过
        for (int i = n - 1; i >= 0; i--)
            // 从 i 开始枚举右端点
            for (int j = i; j < n; j++)
                // 如果左右两端字符相等，才有可能是回文
                if (s[i] == s[j])
                    // 长度小于等于 2 时直接是回文，否则看中间部分是否是回文
                    ispal[i][j] = i + 1 < j ? ispal[i + 1][j - 1] : true;

        // dp[i] 表示 s[0...i] 切分成回文子串所需的最少切割次数
        vector<int> dp(n, INT_MAX);
        // 枚举字符串的结束位置 i
        for (int i = 0; i < n; i++)
        {
            // 如果 s[0...i] 本身就是回文串，不需要切割
            if (ispal[0][i]) dp[i] = 0;
            // 如果 s[0...i] 本身不是回文串，就枚举最后一段回文子串的起点
            else
            {
                // j 表示最后一段回文子串的起始位置
                for (int j = 1; j <= i; j++)
                    // 如果 s[j...i] 是回文子串，就可以在 j 前面切一刀
                    if (ispal[j][i])
                        // 最少切割次数 = s[0...j-1] 的最少切割次数 + 当前这一刀
                        dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        // 返回整个字符串的最少切割次数
        return dp[n - 1];
    }
};