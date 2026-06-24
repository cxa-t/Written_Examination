// https://leetcode.cn/problems/wiggle-subsequence/


class Solution
{
public:
    // 计算最长摆动子序列的长度
    int wiggleMaxLength(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // f[i] 表示以 nums[i] 结尾，并且最后一次差值为正数的最长摆动子序列长度
        vector<int> f(n, 1);
        // g[i] 表示以 nums[i] 结尾，并且最后一次差值为负数的最长摆动子序列长度
        vector<int> g(n, 1);
        // ret 用来记录全局最长摆动子序列长度
        int ret = 1;
        // 从第 1 个元素开始枚举结尾位置
        for (int i = 1; i < n; i++)
        {
            // 枚举 nums[i] 前面的所有元素 nums[j]
            for (int j = 0; j < i; j++)
            {
                // 如果 nums[i] > nums[j]，说明当前差值为正，要接在负差值状态后面
                if (nums[i] > nums[j])
                    f[i] = max(f[i], g[j] + 1);
                // 如果 nums[i] < nums[j]，说明当前差值为负，要接在正差值状态后面
                else if (nums[i] < nums[j])
                    g[i] = max(g[i], f[j] + 1);
            }
            // 更新全局最长摆动子序列长度
            ret = max(ret, max(f[i], g[i]));
        }
        // 返回最长摆动子序列长度
        return ret;
    }
};