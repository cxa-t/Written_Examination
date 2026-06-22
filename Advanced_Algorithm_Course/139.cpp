// https://leetcode.cn/problems/word-break/


class Solution
{
public:
    // 判断字符串 s 是否可以由 wordDict 中的单词拼接而成
    bool wordBreak(string s, vector<string>& wordDict)
    {
        // n 表示字符串 s 的长度
        int n = s.size();
        // dp[i] 表示 s[0...i-1] 是否可以被字典中的单词拼接出来
        vector<bool> dp(n + 1, false);
        // 空字符串默认可以被拼接出来
        dp[0] = true;
        // 哈希表用于快速判断某个字符串是否在 wordDict 中
        unordered_map<string, int> hash;
        // 将 wordDict 中的所有单词存入哈希表
        for (auto& e : wordDict) hash[e]++;
        // 枚举当前要判断的字符串结束位置 i
        for (int i = 1; i <= n; i++)
        {
            // 从后往前枚举最后一个单词的起始位置
            for (int j = i; j > 0; j--)
            {
                // 如果前半部分可以拆分，并且后半部分在字典中
                if (dp[j - 1] && hash.count(s.substr(j - 1, i - j + 1)))
                {
                    // 说明 s[0...i-1] 可以被成功拆分
                    dp[i] = true;
                    // 当前 i 已经可以拆分，不需要继续枚举 j
                    break;
                }
            }
        }
        // 返回整个字符串 s 是否可以被拆分
        return dp[n];
    }
};