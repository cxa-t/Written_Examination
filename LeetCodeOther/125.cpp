// https://leetcode.cn/problems/valid-palindrome/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.size() == 0) return true;
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && left < s.size() - 1 && !isalnum(s[left]))
                left++;
            while (left < right && right >= 0 && !isalnum(s[right]))
                right--;
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};