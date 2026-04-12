//https://leetcode.cn/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<unordered_set>
using namespace std;

class Solution
{
public:

    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int left = 0;
        int right = 0;
        int ret = INT_MIN;
        while (right < s.size())
        {
            while (st.count(s[right]))
            {
                st.erase(s[left++]);
            }
            st.insert(s[right]);
            ret = max((int)st.size(), ret);
            right++;
        }
        return ret == INT_MIN ? 0 : ret;
    }
};

int main()
{
    Solution su;
    string s("aabaab!bb");
    su.lengthOfLongestSubstring(s);

    return 0;
}