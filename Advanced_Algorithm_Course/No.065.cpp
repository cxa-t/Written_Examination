// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/

class Solution
{
public:
    string removeDuplicates(string s)
    {
        if (s.empty()) return "";              // 空字符串直接返回

        stack<char> st;                       // 用栈保存未被消除的字符

        for (int i = 0; i < s.size(); i++)     // 遍历字符串每个字符
        {
            if (st.empty()) st.push(s[i]);     // 栈为空时直接入栈

            else if (s[i] == st.top()) st.pop(); // 当前字符和栈顶相同就消除

            else st.push(s[i]);              // 不相同就入栈
        }

        string ret(st.size(), ' ');           // 创建结果字符串

        for (int i = st.size() - 1; i >= 0; i--) // 从后往前还原字符串
        {
            ret[i] = st.top();                // 取出栈顶字符放入结果
            st.pop();                         // 弹出栈顶字符
        }

        return ret;                           // 返回去重后的字符串
    }
};