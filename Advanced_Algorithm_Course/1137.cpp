// https://leetcode.cn/problems/n-th-tribonacci-number/

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0) return 0;                 // T0 等于 0
        if (n == 1 || n == 2) return 1;       // T1 和 T2 都等于 1

        // vector<int> dp(n + 1);            // 创建 dp 数组保存每一项
        // dp[0] = 0;                        // 初始化 T0
        // dp[1] = dp[2] = 1;                // 初始化 T1 和 T2
        // for(int i = 3; i <= n; i++)       // 从 T3 开始递推
        //     dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; // 状态转移方程
        // return dp[n];                     // 返回第 n 项

        //滚动变量进行空间优化
        int a = 0, b = 1, c = 1, d = 0;      // a、b、c 表示前三项，d 表示当前项
        for (int i = 3; i <= n; i++)          // 从第 3 项开始计算
        {
            d = a + b + c;                   // 当前项等于前三项之和
            a = b;                           // a 向后移动一位
            b = c;                           // b 向后移动一位
            c = d;                           // c 更新为当前项
        }

        return d;                            // 返回第 n 项结果
    }
};