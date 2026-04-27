// https://leetcode.cn/problems/reverse-letters-then-special-characters-in-a-string/

#include <string>
#include <vector>

class Solution
{
public:
    string reverseByType(string s)
    {
        vector<int> is_a;
        vector<int> is_s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z') is_a.push_back(i);
            else is_s.push_back(i);
        }
        int left = 0;
        int right = is_a.size() - 1;
        while (left < right)
        {
            std::swap(s[is_a[left++]], s[is_a[right--]]);
        }
        left = 0;
        right = is_s.size() - 1;
        while (left < right)
        {
            std::swap(s[is_s[left++]], s[is_s[right--]]);
        }
        return s;
    }
};