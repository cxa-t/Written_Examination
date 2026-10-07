// https://leetcode.cn/problems/di-string-match/

class Solution // 定义题解类
{
public: // 公有成员区域
    vector<int> diStringMatch(string s) // 根据字符串 s 中的 'I' 和 'D' 构造一个满足条件的排列
    {
        int n = s.size(); // 获取字符串长度，最终需要构造 n+1 个数字
        int left = 0; // left 表示当前还没有使用的最小数字，初始为0
        int right = s.size(); // right 表示当前还没有使用的最大数字，初始为n
        vector<int> ret(n + 1); // 创建长度为 n+1 的结果数组，用来保存最终排列
        for (int i = 0; i < n; i++) // 遍历字符串中的每一个字符，根据 'I' 或 'D' 决定当前位置放哪个数字
        {
            if (s[i] == 'I') ret[i] = left++; // 如果当前字符是'I'，表示 ret[i] < ret[i+1]，因此当前位置放当前最小值，并让 left 加1
            else ret[i] = right--; // 如果当前字符是'D'，表示 ret[i] > ret[i+1]，因此当前位置放当前最大值，并让 right 减1
        }
        ret[n] = left; // 前 n 个位置处理完成后，left 和 right 会指向同一个剩余数字，将它放到最后一个位置
        return ret; // 返回满足字符串中所有'I'和'D'大小关系的排列
    }
}; 