// https://leetcode.cn/problems/maximum-product-subarray/


class Solution
{
public:
    // 计算数组中乘积最大的连续子数组乘积
    int maxProduct(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // f[i] 表示以 nums[i - 1] 结尾的最大连续子数组乘积
        vector<int> f(n + 1);
        // g[i] 表示以 nums[i - 1] 结尾的最小连续子数组乘积
        vector<int> g(n + 1);
        // 初始化为 1，方便第一个数字直接参与乘法
        f[0] = g[0] = 1;
        // ret 用来记录全局最大乘积
        int ret = INT_MIN;
        // 从第 1 个位置遍历到第 n 个位置
        for (int i = 1; i <= n; i++)
        {
            // 最大乘积可能来自：当前数自己、前一个最大乘积乘当前数、前一个最小乘积乘当前数
            f[i] = max(nums[i - 1], max(f[i - 1] * nums[i - 1], g[i - 1] * nums[i - 1]));
            // 最小乘积也要记录，因为负数乘负数可能变成最大值
            g[i] = min(nums[i - 1], min(g[i - 1] * nums[i - 1], f[i - 1] * nums[i - 1]));
            // 用当前位置结尾的最大乘积更新答案
            ret = max(ret, f[i]);
        }
        // 返回最大连续子数组乘积
        return ret;
    }
};