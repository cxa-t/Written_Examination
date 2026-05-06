// https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    // 检查左边：如果是第一个字符，或者左边字符不等于 ch
                    bool left_ok = (i == 0 || s[i - 1] != ch);
                    // 检查右边：如果是最后一个字符，或者右边字符不等于 ch
                    bool right_ok = (i == n - 1 || s[i + 1] != ch);

                    if (left_ok && right_ok) {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        return s;
    }
};