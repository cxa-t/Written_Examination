// https://leetcode.cn/problems/longest-common-prefix/


class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return "";

        // 以第一个字符串作为基准，逐个字符进行比较
        for (int i = 0; i < strs[0].size(); i++)
        {
            // 取出第一个字符串当前位置的字符
            char tmp = strs[0][i];

            // 从第二个字符串开始，依次和第一个字符串的当前位置字符比较
            for (int j = 1; j < strs.size(); j++)
            {
                // 如果当前位置 i 已经等于某个字符串的长度
                // 说明这个字符串已经结束，不能继续匹配
                // 或者当前位置字符和第一个字符串的字符不同
                // 说明公共前缀到 i 的前一位为止
                if (i == strs[j].size() || tmp != strs[j][i])
                {
                    // 返回从下标 0 开始，长度为 i 的字符串
                    // 也就是已经匹配成功的公共前缀
                    return strs[j].substr(0, i);
                }
            }
        }

        // 如果第一个字符串的所有字符都匹配成功 说明第一个字符串本身就是最长公共前缀
        return strs[0];
    }
};