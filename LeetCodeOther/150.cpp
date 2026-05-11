// https://leetcode.cn/problems/evaluate-reverse-polish-notation/


class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        //思路：
        //这道题用栈模拟逆波兰表达式（后缀表达式）的计算过程：
        //遍历每个 token，如果是数字就直接转成整数压栈；如果是运算符就依次弹出右操作数、左操作数（注意顺序与求值一致），用该运算符计算结果后重新压栈。
        //这里使用包装器可以更好的维护代码
        //遍历完整个数组后，栈顶的唯一值就是表达式的值。
        //之所以用栈，是因为后缀表达式的特性——运算符紧跟在两个操作数之后，天然适合用栈暂存操作数，遇到运算符就回溯最近的两个操作数进行局部求值，直至得到最终结果。
        stack<int> st;
        map<string, function<int(int, int)>> opermap = {
            {"+",[](int x, int y)->int {return x + y; }},
            {"-",[](int x, int y)->int {return x - y; }},
            {"*",[](int x, int y)->int {return x * y; }},
            {"/",[](int x, int y)->int {return x / y; }}
        };
        for (auto& e : tokens)
        {
            //操作符
            if (opermap.count(e))
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                int ret = opermap[e](left, right);
                st.push(ret);
            }
            else
            {
                st.push(stoi(e));
            }
        }
        return st.top();
    }
};