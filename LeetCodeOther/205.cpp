// https://leetcode.cn/problems/isomorphic-strings/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if(s.size() != t.size()) return false; // 如果两个字符串长度不相等，就不可能同构
        unordered_map<char, char> hash1; // 记录 s 中字符到 t 中字符的映射关系
        unordered_map<char, char> hash2; // 记录 t 中字符到 s 中字符的映射关系
        int i = 0; // 定义下标，从第一个字符开始遍历
        while(i < s.size()) // 同时遍历两个字符串的对应位置
        {
            if(hash1.count(s[i]) != 0 && hash1[s[i]] != t[i]) return false; // 如果 s[i] 之前映射过其他字符，说明映射关系发生冲突，返回false
            if(hash2.count(t[i]) != 0 && hash2[t[i]] != s[i]) return false; // 如果 t[i] 之前已经被其他字符映射，说明不同字符映射到了同一个字符，返回false
            hash1[s[i]] = t[i]; // 记录从 s[i] 到 t[i] 的映射关系
            hash2[t[i]] = s[i]; // 记录从 t[i] 到 s[i] 的反向映射关系
            i++; // 下标向后移动，继续检查下一个位置
        }
        return true; // 所有位置都满足双向映射关系，说明两个字符串同构
    }
};