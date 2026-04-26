// https://leetcode.cn/problems/reverse-string-prefix/description/

class Solution {
public:
    string reversePrefix(string s, int k)
    {
        string ret(s);
        int left = 0;
        int right = k - 1;
        while (left < right)
        {
            std::swap(ret[left++], ret[right--]);
        }
        return ret;
    }
};