// https://leetcode.cn/problems/reverse-vowels-of-a-string/

class Solution {
public:
    int check(char c)
    {
        if (c == 'I' || c == 'i' || c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
            return 1;
        else return 0;
    }
    string reverseVowels(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !check(s[left]) && left < s.size()) left++;
            while (left < right && !check(s[right]) && right >= 0) right--;
            std::swap(s[left++], s[right--]);
        }
        return s;
    }
};