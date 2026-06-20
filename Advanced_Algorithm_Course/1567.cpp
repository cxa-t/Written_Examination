// https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/


class Solution
{
public:
    // 计算乘积为正数的最长子数组长度
    int getMaxLen(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // f[i] 表示以 nums[i - 1] 结尾，并且乘积为正数的最长子数组长度
        vector<int> f(n + 1);
        // g[i] 表示以 nums[i - 1] 结尾，并且乘积为负数的最长子数组长度
        vector<int> g(n + 1);
        // ret 用来记录乘积为正数的最长子数组长度
        int ret = -0x3f3f3f3f;
        // 从第 1 个位置遍历到第 n 个位置
        for (int i = 1; i <= n; i++)
        {
            // 如果当前数字是正数
            if (nums[i - 1] > 0)
            {
                // 正数乘正数还是正数，所以正乘积长度加 1
                f[i] = f[i - 1] + 1;
                // 正数乘负数还是负数，如果前面存在负乘积子数组，则长度加 1
                g[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
            }
            // 如果当前数字是负数
            else if (nums[i - 1] < 0)
            {
                // 负数乘负数变正数，如果前面存在负乘积子数组，则长度加 1
                f[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
                // 负数本身可以形成负乘积，或者由前面的正乘积子数组乘负数得到
                g[i] = f[i - 1] + 1;
            }
            // 如果当前数字是 0，f[i] 和 g[i] 默认都是 0，相当于重新开始
            // 用当前位置的正乘积最长长度更新答案
            ret = max(ret, f[i]);
        }
        // 返回乘积为正数的最长子数组长度
        return ret;
    }
};