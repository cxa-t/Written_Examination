// https://leetcode.cn/problems/house-robber-ii/

//第 0 间和第 n - 1 间不能同时偷
//因此拆成两种情况：
//robChild(nums, 0, n - 2)   // 偷的范围不包含最后一间
//robChild(nums, 1, n - 1)   // 偷的范围不包含第一间
//每个线性区间里再用两个状态：
//f[i] = g[i - 1] + nums[i]          // 偷当前房屋
//g[i] = max(f[i - 1], g[i - 1])     // 不偷当前房屋
class Solution
{
public:
    // 计算环形房屋中能偷到的最大金额
    int rob(vector<int>& nums)
    {
        // n 表示房屋数量
        int n = nums.size();
        // 如果没有房屋，最大金额为 0
        if (n == 0) return 0;
        // 如果只有一间房屋，只能偷这一间
        if (n == 1) return nums[0];
        // 环形房屋不能同时偷第 0 间和第 n-1 间，所以拆成两个线性区间求最大值
        int ret = max(robChild(nums, 0, n - 2), robChild(nums, 1, n - 1));
        // 返回两种情况中的最大金额
        return ret;
    }

    // 计算 nums[left...right] 这个线性区间内能偷到的最大金额
    int robChild(vector<int>& nums, int left, int right)
    {
        // 如果区间为空，最大金额为 0
        if (left > right) return 0;
        // n 表示房屋总数量
        int n = nums.size();
        // f[i] 表示偷第 i 间房屋时，在当前区间内能获得的最大金额
        vector<int> f(n);
        // g[i] 表示不偷第 i 间房屋时，在当前区间内能获得的最大金额
        vector<int> g(n);
        // 如果偷 left 位置的房屋，金额就是 nums[left]
        f[left] = nums[left];
        // 从 left + 1 开始遍历到 right
        for (int i = left + 1; i <= right; i++)
        {
            // 如果偷第 i 间房屋，那么第 i-1 间不能偷
            f[i] = g[i - 1] + nums[i];
            // 如果不偷第 i 间房屋，那么第 i-1 间可偷可不偷，取最大值
            g[i] = max(g[i - 1], f[i - 1]);
        }
        // 返回最后一间房屋偷或不偷两种情况的最大值
        return max(f[right], g[right]);
    }
};