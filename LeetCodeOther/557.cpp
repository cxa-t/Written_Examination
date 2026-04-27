// https://leetcode.cn/problems/reverse-words-in-a-string-iii/

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<int> is_space;
        is_space.push_back(-1);
        size_t pos = s.find(' ');
        while (pos != std::string::npos)
        {
            int i = pos;
            is_space.push_back(i);
            pos = s.find(' ', i + 1);
        }
        is_space.push_back(s.size());
        for (int i = 1; i < is_space.size(); i++)
        {
            int left = is_space[i - 1] + 1;
            int right = is_space[i] - 1;
            while (left < right)
            {
                std::swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};