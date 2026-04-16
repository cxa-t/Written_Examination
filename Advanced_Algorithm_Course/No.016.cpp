//https://leetcode.cn/problems/minimum-window-substring/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size()) return "";
        //正确结果
        unordered_map<char, int> hasht;
        for (auto e : t) hasht[e]++;
        int dsize = hasht.size();

        unordered_map<char, int> hashs;
        int left = 0;
        int right = 0;
        int dcount = 0;
        int start = 0;
        int length = INT_MAX;
        while (right < s.size())
        {
            //进窗口维护种类个数
            if (++hashs[s[right]] == hasht[s[right]]) dcount++;

            //判断
            while (dcount == dsize)
            {
                if (dcount == dsize && right - left + 1 < length)
                {
                    length = right - left + 1;
                    start = left;
                }
                if (hashs[s[left]]-- == hasht[s[left]]) dcount--;
                left++;
            }

            right++;
        }

        return length == INT_MAX ? "" : s.substr(start, length);
    }
};

int main()
{
    Solution su;
    string s("ADOBECODEBANC");
    string t("ABC");
    su.minWindow(s, t);
    return 0;
}