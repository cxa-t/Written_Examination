// https://leetcode.cn/problems/masking-personal-information/description/


class Solution {
public:
    // 对邮箱或电话号码进行脱敏处理
    string maskPII(string s) {
        // 查找字符串中是否存在 '@'，用于判断是否是邮箱
        int i = s.find('@');
        // 如果找到了 '@'，说明当前字符串是邮箱
        if (i != -1) {
            // ans 用来保存脱敏后的邮箱
            string ans;
            // 邮箱第一个字符保留，并统一转成小写
            ans += tolower(s[0]);
            // 邮箱中间部分固定替换成 5 个星号
            ans += "*****";
            // 从 '@' 前一个字符开始，一直到邮箱末尾全部保留
            for (int j = i - 1; j < s.size(); ++j) {
                // 将保留部分统一转成小写后加入答案
                ans += tolower(s[j]);
            }
            // 返回脱敏后的邮箱
            return ans;
        }
        // t 用来提取电话号码中的所有数字
        string t;
        // 遍历原字符串中的每个字符
        for (char c : s) {
            // 如果当前字符是数字
            if (isdigit(c)) {
                // 将数字字符加入 t
                t += c;
            }
        }
        // cnt 表示国家码的长度，也就是总数字数减去本地 10 位号码
        int cnt = t.size() - 10;
        // suf 表示电话号码后 10 位的脱敏格式，只保留最后 4 位
        string suf = "***-***-" + t.substr(t.size() - 4);
        // 如果没有国家码，直接返回本地号码格式；否则前面加国家码星号
        return cnt == 0 ? suf : "+" + string(cnt, '*') + "-" + suf;
    }
};