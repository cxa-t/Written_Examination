// https://leetcode.cn/problems/the-masseuse-lcci/


//f[i] = g[i - 1] + nums[i]
//g[i] = max(f[i - 1], g[i - 1])
//也就是：
//选当前预约：上一个预约不能选
//不选当前预约：上一个预约选不选都可以，取最大值
class Solution
{
public:
    // 计算按摩师在不能接相邻预约的情况下，能获得的最长总时长
    int massage(vector<int>& nums)
    {
        // n 表示预约数组的长度
        int n = nums.size();
        // 如果没有预约，最长总时长为 0
        if (n == 0) return 0;
        // f[i] 表示选择第 i 个预约时的最大总时长
        vector<int> f(n);
        // g[i] 表示不选择第 i 个预约时的最大总时长
        vector<int> g(n);
        // 第 0 个预约如果选择，最大总时长就是 nums[0]
        f[0] = nums[0];
        // 从第 1 个预约开始遍历
        for (int i = 1; i < n; i++)
        {
            // 如果选择第 i 个预约，那么第 i-1 个预约不能选
            f[i] = g[i - 1] + nums[i];
            // 如果不选择第 i 个预约，那么第 i-1 个预约可选可不选，取最大值
            g[i] = max(f[i - 1], g[i - 1]);
        }
        // 最终答案是最后一个预约选或不选两种情况的最大值
        return max(f[n - 1], g[n - 1]);
    }
};