// https://leetcode.cn/problems/interleaving-string/


class Solution
{
public:
    // 判断 s3 是否可以由 s1 和 s2 交错组成
    bool isInterleave(string s1, string s2, string s3)
    {
        // m 表示 s1 的长度
        int m = s1.size();
        // n 表示 s2 的长度
        int n = s2.size();
        // 如果 s1 和 s2 的总长度不等于 s3，肯定不能交错组成
        if (m + n != s3.size()) return false;
        // 给 s1 前面加空格，让下标从 1 开始，方便 dp 计算
        s1 = " " + s1;
        // 给 s2 前面加空格，让下标从 1 开始，方便 dp 计算
        s2 = " " + s2;
        // 给 s3 前面加空格，让下标从 1 开始，方便 dp 计算
        s3 = " " + s3;
        // dp[i][j] 表示 s1 前 i 个字符和 s2 前 j 个字符能否组成 s3 前 i+j 个字符
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 两个空字符串可以组成空字符串
        dp[0][0] = true;
        // 初始化第一行：只使用 s2 来匹配 s3
        for (int j = 1; j <= n; j++)
        {
            // 如果 s2 当前字符能和 s3 当前字符匹配，则当前状态为 true
            if (s2[j] == s3[j]) dp[0][j] = true;
            // 一旦不匹配，后面只靠 s2 也不可能继续匹配
            else break;
        }
        // 初始化第一列：只使用 s1 来匹配 s3
        for (int i = 1; i <= m; i++)
        {
            // 如果 s1 当前字符能和 s3 当前字符匹配，则当前状态为 true
            if (s1[i] == s3[i]) dp[i][0] = true;
            // 一旦不匹配，后面只靠 s1 也不可能继续匹配
            else break;
        }
        // 枚举 s1 使用的字符数量
        for (int i = 1; i <= m; i++)
        {
            // 枚举 s2 使用的字符数量
            for (int j = 1; j <= n; j++)
            {
                // 如果 s3 当前字符来自 s1，并且前一个状态可行，则当前状态可行
                if (s1[i] == s3[i + j] && dp[i - 1][j]) dp[i][j] = true;
                // 如果 s3 当前字符来自 s2，并且前一个状态可行，则当前状态可行
                else if (s2[j] == s3[i + j] && dp[i][j - 1]) dp[i][j] = true;
            }
        }
        // 返回 s1 和 s2 是否能组成整个 s3
        return dp[m][n];
    }
};