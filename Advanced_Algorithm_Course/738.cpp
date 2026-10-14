// https://leetcode.cn/problems/monotone-increasing-digits/

class Solution // 定义题解类
{
public: // 公有成员区域
    int monotoneIncreasingDigits(int n) // 返回小于等于 n 的最大单调递增数字，这里的单调递增指每一位数字满足前一位小于等于后一位
    {
        string s = to_string(n); // 将整数 n 转换成字符串，方便逐位修改其中的数字
        int m = s.size(); // 获取数字的位数
        int i = 0; // i 用来寻找第一个不满足单调递增的位置
        while (i + 1 < m && s[i] <= s[i + 1]) i++; // 从左向右检查，只要当前位小于等于下一位，就继续向后寻找
        if (i + 1 == m) return n; // 如果一直检查到最后一位都没有出现下降，说明 n 本身已经是单调递增数字，直接返回 n
        while (i - 1 >= 0 && s[i] == s[i - 1]) i--; // 如果当前位置前面还有和它相同的数字，就不断向左移动，找到这一段相同数字最左边的位置，避免减1后仍然破坏单调性
        s[i]--; // 将找到的位置数字减1，使最终得到的数字一定小于原来的 n，同时为后面构造最大结果创造条件
        for (int j = i + 1; j < m; j++) s[j] = '9'; // 将当前位置后面的所有数字都改成9，使结果在不超过 n 的前提下尽可能大
        return stoi(s); // 将修改后的字符串重新转换成整数并返回
    }
};