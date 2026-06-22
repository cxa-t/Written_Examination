// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/


class Solution
{
public:
    // 计算字符串 s 中有多少个不同的非空子串出现在无限环绕字符串中
    int findSubstringInWraproundString(string s)
    {
        // n 表示字符串 s 的长度
        int n = s.size();
        // dp[i] 表示以 s[i] 结尾的最长连续环绕子串长度
        vector<int> dp(n, 1);
        // 从第 1 个字符开始判断是否能和前一个字符连续
        for (int i = 1; i < n; i++)
        {
            // 如果 s[i] 是 s[i-1] 的下一个字符，或者 z 后面接 a，就说明可以连续
            if ((s[i - 1] + 1 == s[i]) || (s[i - 1] == 'z' && s[i] == 'a'))
                // 当前连续长度等于前一个位置的连续长度加 1
                dp[i] += dp[i - 1];
        }
        // a[c] 表示以字符 c 结尾的最长合法连续子串长度
        int a[26] = { 0 };
        // 遍历每个位置，统计每个结尾字符能贡献的最大子串数量
        for (int i = 0; i < n; i++)
        {
            // 对同一个结尾字符，只保留最长长度，避免重复统计
            a[s[i] - 'a'] = max(dp[i], a[s[i] - 'a']);
        }
        // ret 用来保存最终不同子串数量
        int ret = 0;
        // 每个字符结尾的最长长度，就是该字符能贡献的不同子串数量
        for (auto e : a) ret += e;
        // 返回所有不同合法子串的数量
        return ret;
    }
};