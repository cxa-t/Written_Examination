// https://leetcode.cn/problems/multiply-strings/


class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0") return "0"; // 有一个数为 0，结果就是 0

        int size1 = num1.size();             // num1 的长度
        int size2 = num2.size();             // num2 的长度
        int aux_size = size1 + size2 - 1;    // 临时数组的长度

        vector<int> aux(aux_size, 0);        // 存储每一位乘积累加结果

        for (int i = size2 - 1; i >= 0; i--)  // 从 num2 的个位开始遍历
        {
            int tmp2 = num2[i] - '0';        // 取出 num2 当前数字

            for (int j = size1 - 1; j >= 0; j--) // 从 num1 的个位开始遍历
            {
                int tmp1 = num1[j] - '0';    // 取出 num1 当前数字
                int ret = tmp1 * tmp2;       // 计算两位数字乘积
                aux[i + j] += ret;           // 累加到对应位置
            }
        }

        string ret;                          // 保存最终结果
        int up = 0;                          // 保存进位

        for (int i = aux_size - 1; i >= 0; i--) // 从低位向高位处理进位
        {
            aux[i] += up;                    // 加上上一位产生的进位
            up = aux[i] / 10;                // 计算新的进位
            aux[i] %= 10;                    // 保留当前位数字
        }

        if (up) ret.push_back(up + '0');      // 处理最高位进位

        for (auto e : aux)                    // 遍历每一位结果
        {
            ret.push_back(e + '0');          // 转成字符加入结果
        }

        return ret;                          // 返回字符串乘积
    }
};