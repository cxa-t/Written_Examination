// https://leetcode.cn/problems/reverse-words-with-same-vowel-count/

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int check(string&& tmp)
    {
        int pos = tmp.find_first_of("aeiou");
        int count = 0;
        while (pos != std::string::npos)
        {
            count++;
            pos = tmp.find_first_of("aeiou", pos + 1);
        }
        return count;
    }
    string reverseWords(string s)
    {
        if (s.size() == 0) return s;
        vector<int> is_space;
        is_space.push_back(-1);
        int pos = s.find(' ');
        while (pos != std::string::npos)
        {
            int i = pos;
            is_space.push_back(pos);
            pos = s.find(' ', i + 1);
        }
        is_space.push_back(s.size());

        int stdc = check(string(s.begin(), s.begin() + is_space[1]));
        //cout<<stdc;
        if (is_space.size() < 3) return s;

        for (int i = 2; i < is_space.size(); i++)
        {
            if (check(string(s.begin() + is_space[i - 1] + 1, s.begin() + is_space[i])) > stdc)
            {
                int left = is_space[i - 1] + 1;
                int right = is_space[i] - 1;
                while (left < right)
                {
                    std::swap(s[left++], s[right--]);
                }
            }
            else continue;
        }
        return s;
    }
};


int main()
{
    Solution su;
    string s = "cat and mice";
    su.reverseWords(s);
    return 0;
}