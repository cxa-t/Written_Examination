// https://leetcode.cn/problems/add-binary/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int na = a.size() - 1;          // 指向 a 的最后一位
        int nb = b.size() - 1;          // 指向 b 的最后一位
        string res;                     // 保存反向结果
        int up = 0;                     // 表示进位

        while (nb >= 0 && na >= 0)       // 同时处理 a 和 b
        {
            int numa = a[na] - '0';     // 取出 a 当前位
            int numb = b[nb] - '0';     // 取出 b 当前位
            int ret = (numa + numb + up) % 2; // 当前位结果
            up = (numa + numb + up) / 2;      // 更新进位
            res.push_back(ret + '0');   // 加入结果字符串
            na--;                       // a 指针前移
            nb--;                       // b 指针前移
        }

        while (na >= 0)                  // 处理 a 剩余部分
        {
            int numa = a[na] - '0';     // 取出 a 当前位
            int sum = numa + up;        // 当前位加进位
            int ret = sum % 2;          // 当前位结果
            up = sum / 2;               // 更新进位
            res.push_back(ret + '0');   // 加入结果字符串
            na--;                       // a 指针前移
        }

        while (nb >= 0)                  // 处理 b 剩余部分
        {
            int numb = b[nb] - '0';     // 取出 b 当前位
            int sum = numb + up;        // 当前位加进位
            int ret = sum % 2;          // 当前位结果
            up = sum / 2;               // 更新进位
            res.push_back(ret + '0');   // 加入结果字符串
            nb--;                       // b 指针前移
        }

        if (up) res.push_back(up + '0'); // 处理最后进位
        reverse(res.begin(), res.end()); // 反转得到正确结果
        return res;                     // 返回二进制和
    }
};