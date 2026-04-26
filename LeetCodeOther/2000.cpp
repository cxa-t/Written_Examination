// https://leetcode.cn/problems/reverse-prefix-of-word/

class Solution {
public:
    string reversePrefix(string word, char ch)
    {
        size_t end = word.find(ch);
        if (end == std::string::npos) return word;

        string ret(word);
        size_t left = 0;
        size_t right = end;
        while (left < right)
        {
            std::swap(ret[left++], ret[right--]);
        }
        return ret;
    }
};