// https://leetcode.cn/problems/climbing-stairs/?envType=study-plan-v2&envId=top-100-liked


class Solution
{
public:
    // 计算爬到第 n 阶楼梯的方法数
    int climbStairs(int n)
    {
        // 如果只有 1 阶，只有 1 种爬法
        if (n == 1) return 1;
        // 如果有 2 阶，有 2 种爬法：1+1 或 2
        if (n == 2) return 2;
        // one_step 表示爬到第 i-2 阶的方法数
        int one_step = 1;
        // two_step 表示爬到第 i-1 阶的方法数
        int two_step = 2;
        // ret 表示爬到当前第 i 阶的方法数
        int ret = 0;
        // 从第 3 阶开始递推到第 n 阶
        for (int i = 3; i <= n; i++)
        {
            // 当前方法数 = 前一阶方法数 + 前两阶方法数
            ret = one_step + two_step;
            // 将 i-1 阶的方法数更新为下一轮的 i-2 阶
            one_step = two_step;
            // 将当前 i 阶的方法数更新为下一轮的 i-1 阶
            two_step = ret;
        }
        // 返回爬到第 n 阶的方法数
        return ret;
    }
};