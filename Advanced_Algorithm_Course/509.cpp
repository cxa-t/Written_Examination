// https://leetcode.cn/problems/fibonacci-number/s


class Solution
{
public:
    vector<int> memory;                           // 保存已经计算过的斐波那契结果
    int fib(int n)                                // 计算第n个斐波那契数
    {
        memory.resize(n + 1, -1);                 // 初始化记忆数组并用-1表示尚未计算
        return dfs(n);                            // 通过记忆化递归计算答案
    }
    int dfs(int n)                                // 递归计算第n个斐波那契数
    {
        if (memory[n] != -1)                       // 当前结果已经计算过
            return memory[n];                     // 直接返回缓存结果避免重复计算
        if (n == 0 || n == 1)                      // 判断是否到达递归边界
        {
            memory[n] = n;                        // 保存F(0)=0和F(1)=1
            return memory[n];                     // 返回基础情况的结果
        }
        int ret = dfs(n - 1) + dfs(n - 2);        // 根据递推公式计算当前结果
        memory[n] = ret;                          // 将当前计算结果保存到记忆数组
        return memory[n];                         // 返回第n个斐波那契数
    }
};