
// https://leetcode.cn/problems/backspace-string-compare/

class Solution
{
public:
    string removeSymbol(string s)
    {
        if (s.empty()) return "";                 // 空字符串直接返回

        stack<char> st;                           // 用栈保存有效字符

        for (int i = 0; i < s.size(); i++)        // 遍历字符串每个字符
        {
            if (s[i] == '#' && !st.empty()) st.pop(); // 遇到 # 且栈不空就删除前一个字符
            else if (s[i] != '#') st.push(s[i]);  // 不是 # 就入栈
        }

        string ret(st.size(), ' ');               // 创建结果字符串

        for (int i = st.size() - 1; i >= 0; i--)  // 从后往前还原字符串
        {
            ret[i] = st.top();                    // 把栈顶字符放到对应位置
            st.pop();                             // 弹出栈顶字符
        }

        return ret;                               // 返回处理后的字符串
    }

    bool backspaceCompare(string s, string t)
    {
        s = removeSymbol(s);                      // 处理 s 中的退格符
        t = removeSymbol(t);                      // 处理 t 中的退格符

        return s == t; // 比较两个处理后的字符串
    }
};