// https://leetcode.cn/problems/maximum-sum-circular-subarray/


class Solution
{
public:
    // 计算环形数组中的最大连续子数组和
    int maxSubarraySumCircular(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // f[i] 表示以 nums[i - 1] 结尾的最大连续子数组和
        vector<int> f(n + 1);
        // g[i] 表示以 nums[i - 1] 结尾的最小连续子数组和
        vector<int> g(n + 1);
        // sum 用来记录整个数组的总和
        int sum = 0;
        // 遍历数组，计算总和
        for (int& e : nums) sum += e;
        // 初始化最大子数组和的前置状态为一个很小的数
        f[0] = -0x3f3f3f3f;
        // 初始化最小子数组和的前置状态为一个很大的数
        g[0] = 0x3f3f3f3f;
        // fmax 用来记录全局最大连续子数组和
        int fmax = f[0];
        // gmin 用来记录全局最小连续子数组和
        int gmin = g[0];
        // 从第 1 个位置开始遍历到第 n 个位置
        for (int i = 1; i <= n; i++)
        {
            // 最大子数组和：要么接在前面，要么从当前元素重新开始
            f[i] = max(f[i - 1] + nums[i - 1], nums[i - 1]);
            // 更新全局最大连续子数组和
            fmax = max(f[i], fmax);
            // 最小子数组和：要么接在前面，要么从当前元素重新开始
            g[i] = min(g[i - 1] + nums[i - 1], nums[i - 1]);
            // 更新全局最小连续子数组和
            gmin = min(g[i], gmin);
        }
        // 如果全是负数，不能用 sum - gmin，因为那相当于选了空数组
        if (fmax < 0) return fmax;
        // 返回普通最大子数组和 与 环形最大子数组和 中的较大值
        return max(fmax, sum - gmin);
    }
};