// https://leetcode.cn/problems/longest-palindromic-substring/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int begin = 0;          // 最长回文子串的起始位置
        int len = 0;            // 最长回文子串的长度
        int n = s.size();       // 字符串长度

        for (int i = 0; i < n; i++) // 枚举每个位置作为中心
        {
            int left = i;       // 奇数回文的左边界
            int right = i;      // 奇数回文的右边界

            while (left >= 0 && right < n && s[left] == s[right]) // 向两边扩展
            {
                left--;         // 左边界左移
                right++;        // 右边界右移
            }

            if (right - left - 1 > len) // 判断是否更新最长长度
            {
                begin = left + 1;      // 更新起始位置
                len = right - left - 1; // 更新回文长度
            }

            left = i;           // 偶数回文的左边界
            right = i + 1;      // 偶数回文的右边界

            while (left >= 0 && right < n && s[left] == s[right]) // 向两边扩展
            {
                left--;         // 左边界左移
                right++;        // 右边界右移
            }

            if (right - left - 1 > len) // 判断是否更新最长长度
            {
                begin = left + 1;      // 更新起始位置
                len = right - left - 1; // 更新回文长度
            }
        }

        return s.substr(begin, len); // 返回最长回文子串
    }
};