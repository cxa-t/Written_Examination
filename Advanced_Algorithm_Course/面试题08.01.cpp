// https://leetcode.cn/problems/three-steps-problem-lcci/

class Solution
{
public:
    // 计算走到第 n 阶楼梯的方法数
    int waysToStep(int n)
    {
        // 当 n 为 1 或 2 时，方法数就是 n
        if (n == 1 || n == 2) return n;
        // 当 n 为 3 时，方法数为 4
        if (n == 3) return 4;
        // 取模值，防止结果过大
        int MOD = 1e9 + 7;
        // dp[i] 表示走到第 i 阶楼梯的方法数
        vector<int> dp(n + 1);
        // 走到第 1 阶只有 1 种方法
        dp[1] = 1;
        // 走到第 2 阶有 2 种方法
        dp[2] = 2;
        // 走到第 3 阶有 4 种方法
        dp[3] = 4;
        // 从第 4 阶开始递推计算
        for (int i = 4; i < n + 1; i++)
            // 当前方法数等于前 1、前 2、前 3 阶方法数之和，并取模
            dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
        // 返回走到第 n 阶的方法数
        return dp[n];
    }
};