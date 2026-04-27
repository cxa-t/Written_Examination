// https://leetcode.cn/problems/reverse-only-letters/description/

#include <string>
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isalpha(s[left]) && left < s.size()) left++;
            while (left < right && !isalpha(s[right]) && right >= 0) right--;
            std::swap(s[left++], s[right--]);
        }
        return s;
    }
};


int  main()
{
    Solution su;
    string s = "?6C40E";
    su.reverseOnlyLetters(s);
    return 0;
}