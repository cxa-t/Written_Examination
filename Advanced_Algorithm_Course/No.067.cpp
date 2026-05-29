// https://leetcode.cn/problems/basic-calculator-ii/


class Solution
{
public:
    // 计算只包含 +、-、*、/ 和空格的表达式
    int calculate(string s)
    {
        // 用数组模拟栈，存放最终需要相加的数字
        vector<int> st;
        // 当前遍历到的字符串下标
        int i = 0;
        // 表达式字符串长度
        int n = s.size();
        // 记录当前数字前面的运算符，默认第一个数前面是 '+'
        char op = '+';
        // 从左到右遍历整个表达式
        while (i < n)
        {
            // 如果当前字符是空格，直接跳过
            if (s[i] == ' ') i++;
            // 如果当前字符是数字，就解析出完整的整数
            else if (s[i] >= '0' && s[i] <= '9')
            {
                // 用 tmp 保存当前解析出来的数字
                int tmp = 0;
                // 连续读取多位数字
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    // 将字符数字转换为整数，并累加到 tmp 中
                    tmp = tmp * 10 + (s[i] - '0');
                    // 继续读取下一位字符
                    i++;
                }
                // 如果前一个运算符是 '+'，当前数字直接入栈
                if (op == '+') st.push_back(tmp);
                // 如果前一个运算符是 '-'，当前数字取负后入栈
                else if (op == '-') st.push_back(-tmp);
                // 如果前一个运算符是 '*'，直接和栈顶元素相乘
                else if (op == '*') st.back() *= tmp;
                // 如果前一个运算符是 '/'，直接用栈顶元素除以当前数字
                else st.back() /= tmp;
            }
            // 如果当前字符是运算符，就更新 op
            else
                op = s[i++];
        }
        // 保存最终结果
        int ret = 0;
        // 将栈中所有数字相加，得到表达式结果
        for (auto e : st) ret += e;
        // 返回最终计算结果
        return ret;
    }
};