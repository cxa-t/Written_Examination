// https://leetcode.cn/problems/powx-n/


class Solution
{
public:
    // 计算 x 的 n 次方
    double myPow(double x, int n)
    {
        // 如果 n 是负数，就转化为 1/x 的 -n 次方；否则直接计算 x 的 n 次方
        return n < 0 ? pow(1.0 / x, -(long long)n) : pow(x, n);
    }

    // 使用快速幂递归计算 x 的 n 次方
    double pow(double x, long long n)
    {
        // 任何数的 0 次方都是 1
        if (n == 0) return 1.0;
        // 先递归计算 x 的 n/2 次方
        double tmp = pow(x, n / 2);
        // 如果 n 是偶数，结果就是 tmp * tmp；如果 n 是奇数，还要再乘一个 x
        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
    }
};