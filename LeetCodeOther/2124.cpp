// https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs/?envType=daily-question&envId=2026-11-22

class Solution 
{
public:
    bool checkString(string s) 
    {
        int i = 0; // 定义遍历下标
        for(i = 0; i < s.size(); i++) // 从前向后遍历字符串
        {
            if(s[i] == 'b') break; // 找到第一个'b'，停止遍历
        }
        for(int j = i; j < s.size(); j++) // 从第一个'b'开始检查后续字符
        {
            if(s[j] == 'a') return false; // 如果'b'后面出现'a'，说明顺序不合法
        }
        return true; // 没有出现'b'后接'a'的情况，返回true
    }
};