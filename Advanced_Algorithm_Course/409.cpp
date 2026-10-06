// https://leetcode.cn/problems/longest-palindrome/

class Solution // 定义题解类
{
public: // 公有成员区域
    int longestPalindrome(string s) // 返回使用字符串 s 中的字符能够构成的最长回文串长度
    {
        unordered_map<char, int> hash; // 定义哈希表，key 表示字符，value 表示该字符在字符串中出现的次数
        for (auto e : s) hash[e]++; // 遍历字符串中的每个字符，并统计每个字符出现的次数
        int ret = 0; // 记录当前能够组成的回文串长度
        for (auto [a, b] : hash) ret += b / 2 * 2; // 遍历哈希表，a 是字符，b 是出现次数；每种字符取最大的偶数个加入回文串，例如出现5次只能使用4次
        return ret < s.size() ? ret + 1 : ret; // 如果 ret 小于字符串总长度，说明至少存在一个出现奇数次的字符，可以放在回文串正中间，因此长度加1；否则说明所有字符都已被使用，直接返回 ret
    }
};