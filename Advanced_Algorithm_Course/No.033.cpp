// https://leetcode.cn/problems/is-unique-lcci/

class Solution
{
public:
    bool isUnique(string astr)
    {
        // 利用鸽巢原理来做的优化
        if (astr.size() > 26) return false;
        int bitMap = 0;
        for (auto ch : astr)
        {
            int i = ch - 'a';
            // 判断字符是否已经出现过
            if (((bitMap >> i) & 1) == 1) return false;
            // 把当前字符加入到位图中
            bitMap |= 1 << i;
        }
        return true;
    }
};