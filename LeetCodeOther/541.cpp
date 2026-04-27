// https://leetcode.cn/problems/reverse-string-ii/

class Solution {
public:
    string reverseStr(string s, int k) {
        vector<int> left_pos;
        int pos = 0;
        left_pos.push_back(pos);
        while (pos <= s.size() - 1)
        {
            pos += 2 * k;
            left_pos.push_back(pos);
        }
        for (int i = 0; i < left_pos.size(); i++)
        {
            int left = left_pos[i];
            int right = (left + k - 1) > (s.size() - 1) ? (s.size() - 1) : (left + k - 1);
            while (left < right)
            {
                std::swap(s[left++], s[right--]);
            }
        }
        return s;

    }
};