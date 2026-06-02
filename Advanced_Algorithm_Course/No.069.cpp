// https://leetcode.cn/problems/validate-stack-sequences/

// 按 pushed 顺序模拟入栈，每次入栈后，只要栈顶等于 popped[j]，就立刻弹出。最后栈为空就说明序列合法。
class Solution {
public:
    // 判断 pushed 和 popped 是否是一组合法的栈压入、弹出序列
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        // 辅助栈，用来模拟真实的入栈和出栈过程
        stack<int> st;
        // i 用来遍历 pushed 数组
        int i = 0;
        // j 用来遍历 popped 数组
        int j = 0;
        // 按照 pushed 的顺序依次入栈
        while (i < pushed.size())
        {
            // 将当前 pushed[i] 元素入栈，并让 i 后移
            st.push(pushed[i++]);
            // 只要栈顶等于当前需要弹出的元素，就一直弹栈
            while (!st.empty() && st.top() == popped[j])
            {
                // 弹出栈顶元素
                st.pop();
                // 匹配下一个 popped 中的元素
                j++;
            }
        }
        // 如果最后栈为空，说明弹出序列合法
        if (st.empty()) return true;
        // 否则说明还有元素无法按照 popped 顺序弹出
        else return false;
    }
};